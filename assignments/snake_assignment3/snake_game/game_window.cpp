/* game_window.cpp -------
 *
 * Filename: game_window.cpp
 * Description:
 * Author: Adeel Bhutta
 * Maintainer:
 * Created: Tue Sep  6 14:10:06 2022
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

#include <cstdlib>
#include <ncurses.h>
#include <stdlib.h>
#include <cstring>
#include "game_window.hpp"

gamewindow_t *init_GameWindow(int upper_left_x, int upper_left_y, int width, int height)
{
	gamewindow_t *g;
	g = (gamewindow_t *) malloc(sizeof(gamewindow_t));
	g->upper_left_x = upper_left_x;
	g->upper_left_y = upper_left_y;
	g->width = width;
	g->height = height;
	g->draw_char = '*';
	g->color[0] = 0;
	g->color[1] = 0;
	g->color[2] = 255;
	return (g);
}

void draw_Gamewindow(gamewindow_t *r)
{
	int row_counter, column_counter;

	// Draw Top of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++) {
		mvprintw(r->upper_left_y, row_counter, "%c", r->draw_char);
	}

	// Draw left side of room
	for (column_counter = r->upper_left_y;
		 column_counter <= (r->upper_left_y + r->height);
		 column_counter++) {
		mvprintw(column_counter, r->upper_left_x, "%c", r->draw_char);
	}

	// Draw right side of room
	for (column_counter = r->upper_left_y;
		 column_counter <= (r->upper_left_y + r->height);
		 column_counter++) {
		mvprintw(column_counter, (r->upper_left_x + r->width), "%c", r->draw_char);
	}

	// Draw Bottom of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++) {
		mvprintw(r->upper_left_y + r->height, row_counter, "%c", r->draw_char);
	}
}

gamewindow_t *changeGameWindow(int upper_left_x, int upper_left_y, int width, int height, gamewindow_t *r)
{
	r->upper_left_x = upper_left_x;
	r->upper_left_y = upper_left_y;

	if (width < 10)
		r->width = 10;
	else
		r->width = width;

	if (height < 10)
		r->height = 10;
	else
		r->height = height;

	return (r);
}

void undraw_Gamewindow(gamewindow_t *r)
{
	int row_counter, column_counter;

	// Undraw Top of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++) {
		mvprintw(r->upper_left_y, row_counter, " ");
	}

	// Undraw left side of room
	for (column_counter = r->upper_left_y;
		 column_counter<=(r->upper_left_y + r->height);
		 column_counter++) {
		mvprintw(column_counter, r->upper_left_x, " ");
	}

	// Undraw right side of room
	for (column_counter = r->upper_left_y;
		 column_counter <= (r->upper_left_y + r->height);
		 column_counter++) {
		mvprintw(column_counter, (r->upper_left_x + r->width), " ");
	}

	// Undraw Bottom of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++) {
		mvprintw(r->upper_left_y + r->height, row_counter, " ");
	}
}

gamewindow_t *init_WelcomeWindow(int upper_left_x, int upper_left_y, int width, int height) {
	gamewindow_t *w;
	w = (gamewindow_t *)malloc(sizeof(gamewindow_t));
	w->upper_left_x = upper_left_x;
	w->upper_left_y = upper_left_y;
	w->width = width;
	w->height = height;
	w->color[0] = 0;
	w->color[1] = 0;
	w->color[2] = 0;
	return (w);
}

void draw_WelcomeWindow(gamewindow_t* w) {
	// draws welcome message on the screen and instruction on how to run the game
	char message[20] = "Welcome to snake!";
	mvprintw(w->width/3,(w->height - strlen(message))/2, message);
	strcpy(message, "Enter '1' for Easy");
	mvprintw(w->width/3 + 2,(w->height - strlen(message))/2 - 1, message);
	strcpy(message, "Enter '2' for Hard");
	mvprintw(w->width/3 + 3,(w->height - strlen(message))/2 - 1, message);
	strcpy(message, "Enter '3' for Advanced");
	mvprintw(w->width/3 + 4,(w->height - strlen(message))/2 - 2, message);
	strcpy(message, "Enter 'q' to quit");
	mvprintw(w->width/3 + 5,(w->height - strlen(message))/2, message);
}

void undraw_Welcomewindow(gamewindow_t * w) {
	// un does the the welcome text
	int row_counter, column_counter;

	for(row_counter = w->width/3; row_counter <= w->width/3 +5; row_counter++) {
		for(column_counter = (w->height - 24)/2 - 1; column_counter <= (w->height / 2) + 20; column_counter++) {
			mvprintw(row_counter, column_counter, " ");
		}
	}
}

bool snake_at_boarder(gamewindow_t *r, int x, int y) {
	int row_counter, column_counter;

	// Draw Top of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++) {
		if(r->upper_left_y == y && row_counter == x) 
			return TRUE;
	}

	// Draw left side of room
	for (column_counter = r->upper_left_y;
		 column_counter <= (r->upper_left_y + r->height);
		 column_counter++) {
		if(column_counter == y && r->upper_left_x == x) 
			return TRUE;
		
	}

	// Draw right side of room
	for (column_counter = r->upper_left_y;
		 column_counter <= (r->upper_left_y + r->height);
		 column_counter++) {
		if(column_counter == y && r->upper_left_x + r->width == x)
			return TRUE;
	}

	// Draw Bottom of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++) {
		if(r->upper_left_y + r->height == y && row_counter == x)
			return TRUE;
	}
	return FALSE;
}
/* room.c ends here */
