/*food.cpp -------
*
* Filename: food.cpp
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

#include <cstdlib>
#include <ncurses.h>
#include <cstdbool>
#include "food.hpp"


//Create new food
Food* create_food(int x, int y, enum Type type){
    Food* new_food = (Food*)malloc(sizeof(Food));
     
    new_food->x = x;
    new_food->y = y;
    if (type == Increase){
        (rand() > RAND_MAX/2) ? new_food->type = 'O' : new_food->type = 'P';
    }
    else if(type == Decrease){
        (rand() > RAND_MAX/2) ? new_food->type = 'X' : new_food->type = 'N';
    }
    new_food->next = NULL;

    return new_food;
}

//Check if food exists at coordinates
bool food_exists(Food* foods, int x, int y){
    Food* temp = foods;
    while(temp){
        if(temp->x == x && temp->y == y)
            return true;
        temp = temp->next;
    }
    return false;
}

//Add new food to end of food list
void add_new_food(Food* foods, Food* new_food){
    Food* temp = foods;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = new_food;
}

enum Type food_type(Food* foods, int x, int y){
    //Implement the code to return the type of the food 
    //present at position (x, y)
    Food* temp = foods;
    while(temp){	
        if(temp->x == x && temp->y == y) {
            if (temp->type == 'O' || temp->type == 'P')
                return Increase;
            else if(temp->type == 'X' || temp->type == 'N')
                return Decrease;
        }
        temp = temp->next;
    }
}

Food* remove_eaten_food(Food* foods, int x, int y) {
	//Implement the code to remove food at position (x,y).
	//Create a new linked list of type Food containing only the
	//needed food and return this new list
    Food* temp = foods;
    Food* holder;

    // Check if the first food in the list matches the given coordinates
    if (temp->x == x && temp->y == y) {
        foods = temp->next;  // Update the pointer to the next food object
        free(temp);  // Free the memory occupied by the first food
        return foods;  // Return the updated list (without the removed food)
    }

    // Traverse the linked list to find the food object to be removed
    while (temp->next) {
        if (temp->next->x == x && temp->next->y == y) {
            holder = temp->next->next;  // Store the next node after the food to be removed
            free(temp->next);  // Free the memory occupied by the food to be removed
            temp->next = holder;  // Update the linked list by skipping the removed food
            return foods;  // Return the updated list
        }
        temp = temp->next;  // Move to the next food object in the linked list
    }
    return foods;
}

// Display all the food
void draw_food (Food *foods) {   
    Food* temp = foods;
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    attron(COLOR_PAIR(3));
    while(temp) {
        mvprintw(temp->y, temp->x, "%c", temp->type);
        temp = temp->next;
    }
    attroff(COLOR_PAIR(3));
}
