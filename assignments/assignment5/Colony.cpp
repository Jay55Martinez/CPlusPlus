// Jay Martinez -- Assignment 5 -- 6/11/23
// def file for Colony class
#include "Colony.hpp"
#include "Ant.hpp"
#include "DoodleBug.hpp"
#include <ncurses.h>
#include <string>
#include <algorithm>
using namespace std;

// constructor for Colony
Colony::Colony(int num_ants, int num_doodle, window_s w) {
    // TODO
    this->walls = w.get_out_of_bounds();
    add_bug("Ant", new Ant(12, 30, false));
    add_bug("Ant", new Ant(19, 38, true));
    add_bug("Ant", new Ant(21, 32, false));
    add_bug("Ant", new Ant(17, 28, true));
    add_bug("DoodleBug", new DoodleBug(20, 29));
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

// returns the size of the colony
int Colony::size() const {
    return this->bugs.size();
}

// returns true if there are no ants in the colony
bool Colony::all_ant_dead() const {
    //TODO
    return true;
}

// returns true if the bug would colide with another bug or the wall
bool Colony::colide(int x, int y) const {
    pair<int, int> current_cord = make_pair(x, y);
    // check if it will colide with the wall
    for(const auto& wall : walls) {
        if(current_cord == wall)
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
    for (int i = 0; i < s; i++) {
    bugs[i].second->breed(this);
    }
    this->draw();
}