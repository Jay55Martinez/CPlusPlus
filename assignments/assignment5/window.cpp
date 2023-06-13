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
    vector<pair<int, int>> cords;
    
    for (int row = upper_left_x; row <= upper_left_x + width; row++) {
        cords.push_back(make_pair(upper_left_y, row));
    }

    // Check the left wall of the window
    for (int col = upper_left_y; col <= upper_left_y + height; col++) {
        cords.push_back(make_pair(col, upper_left_x));
    }

    // Check the right wall of the window
    for (int col = upper_left_y; col <= upper_left_y + height; col++) {
        cords.push_back(make_pair(col, upper_left_x + width));
    }

    // Check the bottom wall of the window
    for (int row = upper_left_x; row <= upper_left_x + width; row++) {
        cords.push_back(make_pair(upper_left_y + height, row));
    }

    // Check the area above the window
    for (int row = 0; row < upper_left_y; row++) {
        for (int col = 0; col < width; col++) {
            cords.push_back(make_pair(row, col));
        }
    }

    // Check the area below the window
    for (int row = upper_left_y + height; row < LINES; row++) {
        for (int col = 0; col < width; col++) {
            cords.push_back(make_pair(row, col));
        }
    }

    // Check the area to the left of the window
    for (int row = upper_left_y; row < upper_left_y + height; row++) {
        for (int col = 0; col < upper_left_x; col++) {
            cords.push_back(make_pair(row, col));
        }
    }

    // Check the area to the right of the window
    for (int row = upper_left_y; row < upper_left_y + height; row++) {
        for (int col = upper_left_x + width; col < COLS; col++) {
            cords.push_back(make_pair(row, col));
        }
    }

    return cords;
}