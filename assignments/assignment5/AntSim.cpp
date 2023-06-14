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
    window_s w(10, 10, 110, 30);
    char q;
    int ants;
    int doodles;
    int turn = 0;
    initscr();
    mvprintw(0, 0, "Enter Number of Ants>");
    scanw("%i", &ants);
    mvprintw(0, 0, "Enter Number of DoodleBugs>");
    scanw("%i", &doodles);
    mvprintw(0, 0, "                             ");
    mvprintw(0, 0, "Enter q to quit:");
    mvprintw(3, 0, "Enter any key to step:");
    Colony* c = new Colony(ants , doodles, w);
    // Init board
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    w.draw();
    c->draw();
    while(q != 'q') {
        mvprintw(1, 0, "Cycle: %d", turn);
        q = getch();
        c->step();
        refresh();
        turn++;
    }
    endwin();
    delete c;
}