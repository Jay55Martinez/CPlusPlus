/*game.cpp -------
*
* Filename: game.cpp
* Description:
* Author: Adeel Bhutta
* Maintainer:
* Created: Sat Sep 12 13:16:12 2022
* Last-Updated: September 12 16:51 2022
*
*/

/* Commentary:
*
*
*
*/

/* Change log:
*
*
*/

/*Copyright (c) 2022 Adeel Bhutta
*
* All rights reserved.
*
* Additional copyrights may follow
*/
#include <ncurses.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "snake.hpp"
#include "food.hpp"
#include "game_window.hpp"
#include "key.hpp"
#include "game.hpp"

void welcome() {
    static int row, col, x_offset, y_offset; // screen size and top left corner of 
    gamewindow_t* window;
    char option;
    //Init board
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    getmaxyx(stdscr, row, col);

    window = init_GameWindow(x_offset, y_offset, row, col);
    draw_WelcomeWindow(window);
    // Select option
    while(1) {
        option = getch(); // get chr from user
        if(option == '1') { // easy game selected
            undraw_Welcomewindow(window);
            game(4, 20);
            break;
        }
        if(option == '2') { // hard game selected
            undraw_Welcomewindow(window);
            game(8, 15);
            break;
        }
        if(option == '3') { // advanced game selected
            undraw_Welcomewindow(window);
            game(12, 10);
            break;
        }
        if(option == 'q') // quit
            endwin();
            break;
    }
}

void generate_points(int *food_x, int *food_y, int width, int height, int x_offset, int y_offset){
    *food_x = rand() % (width-1) + x_offset+1;
    *food_y = rand() % (height-1) + y_offset+1;
}
void game(int speed, int food) {
    enum State state = INIT; // Set the initial state
    static int x_max, y_max; //Max screen size variables
    static int x_offset, y_offset; // distance between the top left corner of your screen and the start of the board
    int last_x, last_y; // coords of the last pos of the snakes tail used for adding to the tail
    int score = 0; // the score fo the game
    int update_speed = 100; // updates speed every 100
    int lives = 3; // snake lives
    gamewindow_t *window; // Name of the board
    Snake *snake; // The snake
    Food *foods,*new_food; // List of foods (Not an array)

    const int height = 30; 
    const int width = 70;
    char ch;

    // speed that the game is run at
    struct timespec timeret;
    timeret.tv_sec = 0;
    timeret.tv_nsec = 999999999/speed;

    while(state != EXIT){
        switch(state) {
        case INIT:
            initscr();
            start_color();
            raw(); // line buffering disabled
            nodelay(stdscr, TRUE); //Dont wait for char
            noecho(); // Don't echo input chars
            getmaxyx(stdscr, y_max, x_max);
            keypad(stdscr, TRUE); // making keys work
            curs_set(0); // hide cursor
            timeout(100);

            // Setting height and width of the board
            x_offset = (x_max / 2) - (width / 2);
            y_offset = (y_max / 2) - (height / 2);
            
            //Init board
            window = init_GameWindow(x_offset, y_offset, width, height);
            draw_Gamewindow(window);

            // Init snake
            snake = init_snake(x_offset + (width / 2), y_offset + (height / 2));
            
            // Init foods
            int food_x, food_y, i;
            enum Type type;

            //Generate 20 foods
            srand(time(NULL));
            generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
            type = (rand() > RAND_MAX/2) ? Increase : Decrease; // Randomly deciding type of food
            foods = create_food(food_x, food_y, type);
            for(i = 1; i < food; i++){
                generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                while (food_exists(foods,food_x, food_y))
                    generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                type = (rand() > RAND_MAX/2) ? Increase : Decrease;
                new_food = create_food(food_x, food_y, type);
                add_new_food(foods, new_food);
            }
            state = ALIVE;
            break;

        case ALIVE:
            ch = get_char();
            /* Write your code here */
            if(ch == 'q' || ch == 'Q') // quit the game code
                state = EXIT;
            if (ch == 'p' || ch == 'P') { // pause the game
                while(1) {
                    ch = get_char();
                    mvprintw(10,20, "Key entered: %c", ch);
                    if (ch == 'p' || ch == 'P')
                        break;
                    if(ch == 'q' || ch == 'Q') { // quit the game while in pause
                        state = EXIT;
                        break;
                    }
                }
            }
            // update snakes coord
            last_x = tail_x(snake);
            last_y = tail_y(snake);
            snake = move_snake(snake, ch);

            clear();
            // checks if snake head is where food is
            if (food_exists(foods, snake->x, snake->y)) {
                // remove food, grow snake, increase score
                if(food_type(foods, snake->x, snake->y) == Increase) {
                    foods = remove_eaten_food(foods, snake->x, snake->y);
                    snake = add_tail(snake, last_x, last_y);
                    score += 20;
                }
                // remove food, srink snake, decrease score
                else {
                    foods = remove_eaten_food(foods, snake->x, snake->y);
                    snake = remove_tail(snake);
                    score -= 10;
                }
                // adds new food after the food is eaten
                type = (rand() > RAND_MAX/2) ? Increase : Decrease;
                generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                new_food = create_food(food_x, food_y, type);
                add_new_food(foods, new_food);
            }
            // check death conditions 
            if (eat_itself(snake)) {
                lives--;
                state = INIT;
            }
            if (snake_at_boarder(window, snake->x, snake->y)) {
                lives--;
                state = INIT;
            }
            if (len(snake) <= 1) {
                lives--;
                state = INIT;
            }
            if (lives == 0) {
                state = DEAD;
                break;
            }

            // updates speed every 100 points
            if (score >= update_speed) {
                timeret.tv_nsec /= 2; // double speed
                update_speed += 100;
            }
            // Draw everything on the screen
            mvprintw(0, x_max - 50,
             "snake head x: %i snake head y: %i snake tail x: %i snake tail y: %i", snake->x, snake->y, last_x, last_y);
            mvprintw(2, 0, "Key entered: %c", ch);
            mvprintw(0, 0, "score: %i", score);
            mvprintw(1, 0, "lives: %i", lives);
            draw_Gamewindow(window);
            draw_snake(snake);
            draw_food(foods);
            break;
        case DEAD:
            
            state = EXIT;
            break;
        case EXIT:
            clear(); 
            refresh();
            endwin();
            break;
        }
        refresh();
        nanosleep(&timeret, NULL);
    }
}
