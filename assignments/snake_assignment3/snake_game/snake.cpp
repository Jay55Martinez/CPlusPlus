/* snake.cpp -------
 *
 * Filename: snake.cpp
 * Description:
 * Author: Adeel Bhutta
 * Maintainer:
 * Created: Sun Sep 13 9:12:30 2022
 * Last-Updated: September 13 22:40 2022
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

/* Copyright (c) 2022 Adeel Bhutta
 *
 * All rights reserved.
 *
 * Additional copyrights may follow
 */

#include <cstring>
#include <cstdbool>
#include <cstdlib>
#include "snake.hpp"
#include "key.hpp"
#include <ncurses.h>

// Initialize snake
Snake *init_snake(int x, int y)
{
  Snake *head = create_tail(x, y);
  Snake *tail1 = create_tail(x - 1, y);
  Snake *tail2 = create_tail(x - 2, y);
  tail1->next = tail2;
  head->next = tail1;
  head->color[0] = 0;
  head->color[1] = 255;
  head->color[2] = 0;
  return head;
}

// Initialize obstacle
Snake *init_obstacle(int x, int y)
{
  Snake *head = create_tail(x, y);
  head->color[0] = 255;
  head->color[1] = 0;
  head->color[2] = 0;
  return head;
}

// Creates one tail
Snake *create_tail(int x, int y)
{
  Snake *snake = new Snake;
  snake->color[0] = 0;
  snake->color[1] = 255;
  snake->color[2] = 0;
  /* snake->color = {0, 0, 255}; */
  snake->symbol = '#';
  snake->next = NULL;
  snake->x = x;
  snake->y = y;
  return snake;
}


// Adds a tail to the snake
Snake* add_tail(Snake* snake, int x, int y) {
  Snake *end = snake;
  while (end->next)
    end = end->next;
  end->next = create_tail(x, y);
  return snake;
}

// Adds a tail to the snake
Snake* add_obstacle(Snake* snake, int x, int y) {
  Snake *end = snake;
  while (end->next)
    end = end->next;
  end->next = init_obstacle(x, y);
  return snake;
}

// Moves the snake in the input direction
Snake *move_snake(Snake *snake, int direction)
{
  int prev_x, prev_y, new_x, new_y;
  prev_x = snake->next->x;
  prev_y = snake->next->y;
  // TODO
  Snake *new_head = new Snake;
  new_x = snake->x;
  new_y = snake->y;

  if(prev_x == snake->x) {
    if(prev_y == snake->y-1)
      new_y = snake->y+1;
    else
      new_y = snake->y-1;
  }
  else {
    if(prev_x == snake->x-1)
      new_x = snake->x+1;
    else 
      new_x = snake->x-1;
  }
  // Set the new head to have the x and y coordinates as the existing head of the snake

  switch (direction)
  {
  case UP:
    // Write code to make the new head go up by 1 cell
    if (prev_y == snake->y-1)
    break;
    new_x= snake->x;
    new_y= snake->y-1;
    break;
  case DOWN:
    // Write code to make the new head go down by 1 cell
    if (prev_y == snake->y+1)
    break;
    new_x = snake->x;
    new_y = snake->y+1;
    break;
  case RIGHT:
    // Write code to make the new head go right by 1 cell
    if (prev_x == snake->x+1)
    break;
    new_x = snake->x+1;
    new_y = snake->y;
    break;
  case LEFT:
    // Write code to make the new head go left by 1 cell
    if (prev_x == snake->x-1)
    break;
    new_x = snake->x-1;
    new_y = snake->y;
    break;
  default:
    break;
    //deafault case the snake keeps going forward
  }

  // Set new head as the new head of the entire snake
  // Add all the features (color and symbol) to the new cell
  // Delete the tail from the snake: HINT - there is a remove tail function below
  new_head = create_tail(new_x, new_y);
  new_head->next = snake;
  remove_tail(new_head);
  return new_head;
}

Snake *remove_tail(Snake *snake)
{
  Snake *end = snake;
  while (end->next->next)
    end = end->next;
  free(end->next);
  end->next = NULL;
  return snake;
}

// draws the snake on the board
void draw_snake(Snake *snake)
{
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  attron(COLOR_PAIR(2));
  while (snake)
  {
    mvprintw(snake->y, snake->x, "%c", snake->symbol);
    snake = snake->next;
  }
  attroff(COLOR_PAIR(2));
}

int len(Snake* snake) {
  Snake* temp = snake;
  int count = 0;
  while(temp) {
    count++;
    temp = temp->next;
  }
  return count;
}

int tail_x(Snake* snake) {
  Snake *end = snake;
  while (end->next)
    end = end->next;
  return end->x;
}

int tail_y(Snake* snake) {
  Snake *end = snake;
  while (end->next)
    end = end->next;
  return end->y;
}

// checks if it eats itself, if it does, then return true
bool eat_itself(Snake *snake)
{
  Snake* temp = snake->next;
  while(temp) {
    if(temp->x == snake->x && temp->y == snake->y) {
      return TRUE;
    }
    temp = temp->next;
  }
  return false;
}

// checks if one snake colides with another, then returns true
bool snake_colide(Snake* snake, Snake* snake2)
{
  Snake* temp = snake2;
  while(temp) {
    if(temp->x == snake->x && temp->y == snake->y) {
      return TRUE;
    }
    temp = temp->next;
  }
  return false;
}
