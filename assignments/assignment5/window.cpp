// Jay Martinez -- Assignment 5 -- 6/11/23
/*
class window_s : Displays a ncurses window for the ant sim
*/
#include "window.hpp"
#include <ncurses.h>
using namespace std;

// constructor
window_s::window_s (int x, int y, int w, int h) {
    this->upper_left_x = x;
    this->upper_left_y = y;
    this->width = w;
    this->height = h;
    this->draw_char = '*';
}

// setter for char
void window_s::set_char(const char c) {
    this->draw_char = c;
}


// draws the window for simulation
void window_s::draw() const {
    int row_counter, column_counter;
	// Draw Top of room
	for (row_counter = this->upper_left_x;
		 row_counter <= (this->upper_left_x + this->width);
		 row_counter++) {
		mvprintw(this->upper_left_y, row_counter, "%c", this->draw_char);
	}

	// Draw left side of room
	for (column_counter = this->upper_left_y;
		 column_counter <= (this->upper_left_y + this->height);
		 column_counter++) {
		mvprintw(column_counter, this->upper_left_x, "%c", this->draw_char);
	}

	// Draw right side of room
	for (column_counter = this->upper_left_y;
		 column_counter <= (this->upper_left_y + this->height);
		 column_counter++) {
		mvprintw(column_counter, (this->upper_left_x + this->width), "%c", this->draw_char);
	}

	// Draw Bottom of room
	for (row_counter = this->upper_left_x;
		 row_counter <= (this->upper_left_x + this->width);
		 row_counter++) {
		mvprintw(this->upper_left_y + this->height, row_counter, "%c", this->draw_char);
	}
}

// returns all of the cords that are out of bounds
vector<pair<int, int>> window_s::get_out_of_bounds() const {
    int offset = 16;
    vector<pair<int, int>> cords;

    for (int i = 0; i < offset; i++) {
        int startX = this->upper_left_x - i;
        int startY = this->upper_left_y - i;
        int endX = this->upper_left_x + this->width + i;
        int endY = this->upper_left_y + this->height + i;

        // Draw top side of the window
        for (int x = startX; x <= endX; x++) {
            cords.push_back(make_pair(startY, x));
        }

        // Draw bottom side of the window
        for (int x = startX; x <= endX; x++) {
            cords.push_back(make_pair(endY, x));
        }

        // Draw left side of the window
        for (int y = startY; y <= endY; y++) {
            cords.push_back(make_pair(y, startX));
        }

        // Draw right side of the window
        for (int y = startY; y <= endY; y++) {
            cords.push_back(make_pair(y, endX));
        }
    }

    return cords;
}

// getters
int window_s::get_width() const { return this->width; }
int window_s::get_height() const { return this->height; }
int window_s::get_offsetx() const { return this->upper_left_x; }
int window_s::get_offsety() const { return this->upper_left_y; }