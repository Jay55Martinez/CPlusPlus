// Jay Martinez -- Assignment 5 -- 6/10/23
// Def file for ant
#include "Ant.hpp"

Ant::Ant(int x, int y, bool sx) : Bug(x, y, sx) {
    this->last_moved = 0;
}

// moves the ant by updating its x y cords
void Ant::move(Colony* c) {// rand seed based on time
    int dx = rand()%3 - 1; // range -1 - 1
    int dy = rand()%3 - 1; // range -1 - 1
    // makes sure that the bug always makes a valid move
    while(c->colide(get_cord().first + dx, get_cord().second + dy)) {
        dx = rand()%3 - 1; // range -1 - 1
        dy = rand()%3 - 1; // range -1 - 1
    }
    // checks if the ant has moved if it has not then ++ last_moved
    if(get_cord() == std::make_pair(get_cord().first + dx, get_cord().second + dy))
        ++last_moved;
    // updates the ants new cords
    set_cord(this->get_cord().first + dx, this->get_cord().second + dy);
}

// if breed condition is true
void Ant::breed(Colony* c) {} // does nothing to the worker ands

// if the starve condition is true then remove Ant from memory
void Ant::starve(bool eaten, Colony* c) {
    if(eaten) {
        this->undraw();
        c->remove_bug_at(this->get_cord());
    }
    else if(last_moved >= 5) {
        this->undraw();
        c->remove_bug_at(this->get_cord());
    }
}