// Jay Martinez -- Assignment 5 -- 6/11/23
// def file for Colony class
#include "Colony.hpp"
#include "Ant.hpp"
#include "DoodleBug.hpp"
#include "QAnt.hpp"
#include <ncurses.h>
#include <algorithm>
using namespace std;

// constructor for Colony
Colony::Colony(int num_ants, int num_doodle, window_s* w) {
    // TODO
    this->window = w;
    int y = rand() % w->get_width() + w->get_offsetx()+1;
    int x = rand() % w->get_height() + w->get_offsety()+1;
    this->walls = w->get_out_of_bounds();
    // spawn ants
    for(int a=0; a<num_ants-1; a++) {
        while(colide(x, y)) {
            y = rand() % w->get_width() + w->get_offsetx()+1;
            x = rand() % w->get_height() + w->get_offsety()+1;
        }
        spawn_ant_random(x, y);
    }
    
    y = rand() % w->get_width() + w->get_offsetx()+1;
    x = rand() % w->get_height() + w->get_offsety()+1;
    // spawn doodlebugs
    for(int d=0; d<num_doodle; d++) {
        while(colide(x, y)) {
            y = rand() % w->get_width() + w->get_offsetx()+1;
            x = rand() % w->get_height() + w->get_offsety()+1;
        }
        add_bug("DoodleBug", new DoodleBug(x, y));
    }
    // Add 1 queen
    while(colide(x, y)) {
            y = rand() % w->get_width() + w->get_offsetx()+1;
            x = rand() % w->get_height() + w->get_offsety()+1;
    }
    add_bug("Ant", new QAnt(x, y));
}

// draws all of the bugs on the screen
void Colony::draw() const {
    for(const auto& bug : bugs) {
        bug.second->draw();
    }
}

// adds a bug to the set of bugs
void Colony::add_bug(string type, Bug* b) {
    this->bugs.push_back(pair<string, Bug*>(type, b));
}

// spawns an ant with the distrubution odds of 70% females 29% males and 1% Queen
void Colony::spawn_ant_random(int x, int y) {
    int r = rand()%99 + 1; // 1 - 100
    if(r == 1) { // queen ant
        add_bug("Ant", new QAnt(x, y));
    }
    else if(1 < r && r < 71) { // female worker ant
        add_bug("Ant", new Ant(x, y, true)); 
    }
    else { // male ant
        add_bug("Ant", new Ant(x, y, false));
    }

}

// returns the size of the colony
int Colony::size() const {
    return this->bugs.size();
}

// returns true if there are no ants in the colony
bool Colony::all_ant_dead() const {
    for(auto& bug : bugs) {
        if(bug.first == "Ant")
            return true;
    }
    return false;
}

// returns true if the bug would colide with another bug or the wall
bool Colony::colide(int x, int y) const {
    pair<int, int> current_cord = make_pair(x, y);
    // check if it will colide with the wall
    if(y <= window->get_offsetx() || x <= window->get_offsety()) {
        mvprintw(5, 0, "%i <= %i || %i <= %i : TRUE", y, window->get_offsetx(), x, window->get_offsety());
        return true;
    }
    else if(y >= (window->get_offsetx() + window->get_width()) ||
            x >= (window->get_offsety() + window->get_height())) {
        mvprintw(5, 0, "Other one True");
        return true;
    }
    // check if it will colide with anther bug
    for(const auto& bug : bugs) {
        if(current_cord == bug.second->get_cord())
            return true;
    }
    return false;
}

// returns true if there is an ant at the given cords
bool Colony::ant_at(int x, int y) const {
    pair<int, int> current_cord = make_pair(x, y);
    // check if it will colide with anther bug
    for(const auto& bug : bugs) {
        if(bug.first == "Ant") {
            if(current_cord == bug.second->get_cord())
                return true;
        }
    }
    return false;
}

// returns false if is a male / true if female
bool Colony::get_gender(int x, int y) {
    pair<int, int> current_cord = make_pair(x, y);
    // check if it will colide with anther bug
    for(const auto& bug : bugs) {
        if(bug.first == "Ant") {
            if(current_cord == bug.second->get_cord()) {
                return bug.second->get_sex();
            }
        }
    }
    return true;
}

// returns the cords of any ants that surround the given cord returns the same cords if no ants found
pair<int, int> Colony::next_to_ant(int x, int y) const {
    // bug with this code
    for(int i = -1; i<=1; i++) {
        for(int j = -1; j<=1; j++) {
            if(ant_at(x+i, y+j))
                return std::make_pair(x+i, y+j);
        }
    }
    return std::make_pair(x, y);
}

// moves the doodlebugs first then removes all eaten ants finaly moves the ants
void Colony::move() {
    vector<Bug*> ants;
    // doodlebug moves first and eats the ants
    for(auto& bug : bugs) {
        if(bug.first == "DoodleBug") {
            bug.second->undraw();
            bug.second->move(this);
        }
        else 
            ants.push_back(bug.second);
    }
    // ants move
    for(auto& ant : ants) {
        ant->undraw();
        ant->move(this);
    }
}

// removes the bug at the given cord from the bugs vector
void Colony::remove_bug_at(pair<int, int> c) {
    for(int i = 0 ; i<size(); i++) {
        if(c == bugs[i].second->get_cord()) {
            bugs.erase(bugs.begin()+i);
        }
    }
}

// steps through a whole cycle, move, starve, breed
void Colony::step() {
    this->move();
    // checks if the bugs should starve
    for_each(bugs.begin(), bugs.end(), [&] (pair<string, Bug*> bug) {
        bug.second->starve(false, this);
    });
    // checks if the bugs should breed
    int s = bugs.size();
    this->draw();
}