/* game_windows.hpp ---------
 *
 * Filename: game_window.hpp
 * Description:
 * Author: Adeel Bhutta
 * Maintainer:
 * Created: Tue Sep  6 14:10:53 2022
 * Last-Updated: June 4 11:00 2022
 * Keywords:
 * Compatibility:
 *
 */

/* Commentary:
 *
 *
 *
 */

/* Change log:
 * new functions:
 * init_WelcomeWindow
 * 
 *
 */

/* Copyright (c) 2022 Adeel Bhutta
 *
 * All rights reserved.
 *
 * Additional copyrights may follow
 */

/* Code: */
#include <string>
#define WELL_WIDTH 50
#define WELL_HEIGHT 25

struct gamewindow_t
{
  int upper_left_x;
  int upper_left_y;
  int width;
  int height;
  char draw_char;
  char color[3];
};

typedef struct gamewindow_t gamewindow_t;

gamewindow_t *init_GameWindow(int, int, int, int);
gamewindow_t *changeGameWindow(int upper_left_x, int upper_left_y, int width, int height, gamewindow_t *);
gamewindow_t *init_WelcomeWindow(int, int, int, int); // Welcome and GameOver use the same window

void undraw_Gamewindow(gamewindow_t *);
void draw_Gamewindow(gamewindow_t *);
void draw_WelcomeWindow(gamewindow_t *);
void draw_GameOverWindow(gamewindow_t *);

bool snake_at_boarder(gamewindow_t *r, int x, int y);