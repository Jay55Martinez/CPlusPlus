// Jay Martinez -- Assignment 5 -- 6/11/23
// main file for the program
#include "Colony.hpp"
#include "Ant.hpp"
#include <ncurses.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void) {
    srand(time(0));
    window_s w(10, 10, 100, 30);
    Ant* b = new Ant(30, 23, true);
    Colony* c = new Colony(0 , 0, w);
    char q;
    //Init board
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    w.draw();
    c->draw();
    while(q != 'q') {
        q = getch();
        c->step();
        refresh();
    }
    endwin();
    delete b;
    delete c;
}