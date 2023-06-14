// Jay Martinez -- Assignment 5 -- 6/10/23
/*
class Bug : interface

members: 
pair<int, int> cord : x, y cords for the bug
char symbol : symbol that will be displayed for the bug
bool sex : true = female / false = male

constructor:
Bug(int x, int y, char s) : constructor for the bug class
Bug(int x, int y, bool sx) : constructor for ant

functions :
+ void draw() const : draws the bug
+ void undraw() const : undraws the bug
+ void move(Colony* c) : moves the bug to a random tile that is one space away.
If the bug tries to move to where a wall would be they bounce off it. Also bugs can't move
on top of each other.
+ void starve(bool eaten, Colony* c) : removes the bug from memory when it passes a condition is true or given bool is true
+ void breed(Colony* c) : if breed conditions are true adds Bugs to Colony
+ pair<int, int> get_cord() const : gets the x, y cords of the bug
+ char get_symbol() const : gets the symbol of the bug
+ bool get_sex() const : gets the sex of the bug true = female / false = male
+ set_cord(int x, inty) - set_cord(pair<int,int> c): setter function for cord.


*/
#ifndef COLONY_HPP
#define COLONY_HPP
#include "Colony.hpp"
#include <utility>
#include <string>
#include <ncurses.h>
using namespace std;

class Colony;

class Bug {
    public:
        // constructor
        Bug(int x, int y, char s);
        Bug(int x, int y, bool sx);
        // moves the bug by updating the x, y cords
        virtual void move(Colony* c) = 0;
        // removes bug from memory when condions are met
        virtual void starve(bool eaten, Colony* c) = 0;
        // if breed conditions are met then Bugs are added to the colony
        virtual void breed(Colony* c) = 0;
        // draws the bug using ncurses library
        void draw() const;
        // un draws the bug 
        void undraw() const;
        // gets the x, y cords of the bug
        pair<int, int> get_cord() const;
        // gets the symbol of the bug
        char get_symbol() const;
        // gets the sex of the bug
        bool get_sex() const;
        // setter for cords
        void set_cord(int x, int y);
        void set_cord(pair<int, int> c);
    private:
        pair<int, int> cords; // x, y cords for bug
        bool sex; // true = female / false = male
        char symbol; // symbol that would be displayed for the Bug
};
#endif