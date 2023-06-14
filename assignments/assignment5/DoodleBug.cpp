// Jay Martinez -- Assignment 5 -- 6/10/23
// def file
#include "DoodleBug.hpp"
#include <string>

//constructor 
DoodleBug::DoodleBug(int x, int y) : Bug(x, y, 'X') {
    this->last_eaten = 0;
    this->survive_time = 0;
};

// moves the doodle bug 
// if there is ant in its surounding tiles it will move there every time
void DoodleBug::move(Colony* c) {
    pair<int, int> ant_c = c->next_to_ant(get_cord().first, get_cord().second);
    if(get_cord() != ant_c) {
        c->remove_bug_at(ant_c);
        set_cord(ant_c);
        this->last_eaten = 0;
    }
    else { // rand seed based on time
        int dx = rand()%3 - 1; // range -1 - 1
        int dy = rand()%3 - 1; // range -1 - 1
        int max_attempts = 100; 
        int attempts = 0; 
        // makes sure that the bug always makes a valid move
        while(c->colide(get_cord().first + dx, get_cord().second + dy) && attempts < max_attempts) {
            dx = rand()%3 - 1; // range -1 - 1
            dy = rand()%3 - 1; // range -1 - 1
        }
        // updates the member variables 
        ++survive_time;
        ++last_eaten;
        // updates the ants new cords
        set_cord(get_cord().first + dx, get_cord().second + dy);
    }
}

// removes the bug from memory if meets curtain conditions
void DoodleBug::starve(bool eaten, Colony* c) {
    if(this->last_eaten >= 10) {
        this->undraw();
        c->remove_bug_at(this->get_cord());
    }
    else if(eaten) {
        this->undraw();
        c->remove_bug_at(this->get_cord());
    }
}

// if breed conditions are true then adds bugs to the Colony
void DoodleBug::breed(Colony* c) {
    if((survive_time % 10) == 0 ) {
        // spawns 2 doodlebugs 
        for(int i = 0; i < 2; i++) {
            int dx = rand()%15 + 1;
            int dy = rand()%15 + 1;
            while(c->colide(get_cord().first + dx, get_cord().second + dy)) {
                dx = rand()%15 + 1;
                dy = rand()%15 + 1;
            }
            c->add_bug("DoodleBug", new DoodleBug(get_cord().first + dx, get_cord().second + dy));
        }
    }
}