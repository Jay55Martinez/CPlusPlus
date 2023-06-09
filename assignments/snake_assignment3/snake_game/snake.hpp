/* snake.hpp -------
 *
 * Filename: snake.hpp
 * Description:
 * Author: Adeel Bhutta
 * Maintainer:
 * Created: Sun Sep 13 21:01:02 2022
 * Last-Updated: September 13 22:43 2022
 *
 */

/* Commentary:
 *
 *
 *
 */

/* Change log:
 * added functions:
 tail_x
 tail_y
 add_tail
 *
 */

/* Copyright (c) 2022 Adeel Bhutta
 *
 * All rights reserved.
 *
 * Additional copyrights may follow
 */


#include <cstdbool>

struct Snake {
  int x;
  int y;
  int speed;
  char color[3];
  char symbol;
  struct Snake* next;
};

typedef struct Snake Snake;

Snake* init_snake(int x, int y);
Snake* init_obstacle(int x, int y);
Snake* create_tail(int x, int y);
Snake* move_snake(Snake* snake, int direction);
Snake* add_tail(Snake* snake, int x, int y);
Snake* add_obstacle(Snake* snake, int x, int y);
void draw_snake(Snake* snake);
bool eat_itself(Snake* snake);
bool snake_colide(Snake* snake, Snake* snake2);
Snake* remove_tail(Snake* snake);
int len(Snake* snake);
int tail_x(Snake* snake);
int tail_y(Snake* snake);
