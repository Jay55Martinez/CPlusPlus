// Jay Martinez -- Assignment 5 -- 6/13/23
// def file
#include "QAnt.hpp"

QAnt::QAnt(int x, int y) : Bug(x, y, 'Q') {
    this->survive_time = 0;
    this->bred = false;
}

// moves the ant by updating its x y cords
void QAnt::move(Colony* c) {// rand seed based on time
    if(!this->bred) {
        int dx = rand()%3 - 1; // range -1 - 1
        int dy = rand()%3 - 1; // range -1 - 1
        // makes sure that the bug always makes a valid move
        while(c->colide(get_cord().first + dx, get_cord().second + dy)) {
            dx = rand()%3 - 1; // range -1 - 1
            dy = rand()%3 - 1; // range -1 - 1
        }
        // update survive_time
        ++survive_time;
        // checks if there are any male ants around to bred
        if(survive_time > 30) {
            pair<int, int> ant_c = c->next_to_ant(get_cord().first, get_cord().second);
            if(get_cord() != ant_c && !(c->get_gender(ant_c.first, ant_c.second))) {
                this->bred = true;
            }
        }
        // updates the ants new cords
        set_cord(this->get_cord().first + dx, this->get_cord().second + dy);
    }
}

// if breed condition is true
void QAnt::breed(Colony* c) {
    if(bred) {
        // spawns 10 ants 
        for(int i = 0; i < 10; i++) {
            int dx = rand()%15 + 1;
            int dy = rand()%15 + 1;
            while(c->colide(get_cord().first + dx, get_cord().second + dy)) {
                dx = rand()%15 + 1;
                dy = rand()%15 + 1;
            }
            c->spawn_ant_random(get_cord().first + dx, get_cord().second + dy);
        }
        this->bred = false;
        this->survive_time = 15;
    }
}

// if the starve condition is true then remove Ant from memory
void QAnt::starve(bool eaten, Colony* c) {
    if(survive_time > 60) {
        this->undraw();
        c->remove_bug_at(this->get_cord());
    }
} // queens never starve