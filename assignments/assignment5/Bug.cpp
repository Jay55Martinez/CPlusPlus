// Jay Martinez -- Assignment 5 -- 6/10/23
// Deffiniotion of bug class
#include "Bug.hpp"
#include <random>
using namespace std;

// constructor for Bug
Bug::Bug(int x, int y, char s) {
    this->cords = std::make_pair(x, y);
    this->symbol = s;
}

Bug::Bug(int x, int y, bool sx) {
    this->cords = std::make_pair(x, y);
    this->sex = sx;
    if (sx)
        this->symbol = 'w';
    else 
        this->symbol = 'o';
}


// draws the bug using ncurses library
void Bug::draw() const {
    mvprintw(this->cords.first, this->cords.second, "%c", this->symbol);
}

// undraws the bug 
void Bug::undraw() const {
    mvprintw(this->cords.first, this->cords.second, " ");
}

// gets the x, y cords of the bug
pair<int, int> Bug::get_cord() const {
    return this->cords;
}

// getter
char Bug::get_symbol() const {
    return this->symbol;
}

// getter
bool Bug::get_sex() const {
    return this->sex;
}

// setter for cords
void Bug::set_cord(int x, int y) {
    this->cords = std::make_pair(x, y);
}

// overloading set_cord
void Bug::set_cord(pair<int, int> c) {
    this->cords = c;
}