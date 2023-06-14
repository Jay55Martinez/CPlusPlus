// Jay Martinez -- Assignment 5 -- 6/11/23
/*
class Colony : contains all Bugs that are being simulated 
members:
vector<pair<string, Bug*>> bugs : contains all of the bugs used in the simulation. Key -> type of bug
vector<pair<int, int>> walls : map of all the walls x is the key

constructor:
Colony(int, int, window_s) : takes in the number of ants you want and number of doodle bugs
initializes teh vectors of bugs so that it contains queen and other ants and doodles

functions:
+ void draw() : draws all of the bugs contained in the colony
+ int size() : returns how many bugs are in teh colony
+ void add_Bug(string, Bug&) : adds a bug to the colony
+ bool all_ants_dead(): returns true if all the ants in the colony is dead
+ bool colides(int x, int y) const: returns true if the bug would colide with the wall or another bug
+ bool ant_at(int x, int y) const: returns true if there is an ant at the given cord
+ pair<int, int> next_to_ant(int x, int y) const: returns the cord of an ant that is in a tile around the 
given cord. if no ant is present returns the same cords
+ void move() : moves the doodlebugs first, removes all eaten ants then moves the ants
+ void step() : runs a whole cycle by running moves, starves, breeds
+ void remove_bug_at(int x, int y) : removes a bug from the list at the given cord
+ void spawn_ant_random(int x, int y) : spawns an ant with the distrubution odds of 70% females 29% males and 1% Queen
at specifed x, y cords
+ bool get_gender(int x, int y) : gets the gender of the bug at given cord
*/
#ifndef BUG_HPP
#define BUG_HPP
#include "Bug.hpp"
#include "window.hpp"
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Bug;
class window_s;
class Ant;
class DoodleBug;

class Colony {
    public:
        // constructor
        Colony(int num_ants, int num_doodle, window_s w);
        // draws all of the 
        void draw() const;
        // adds a bug to the set of bugs
        void add_bug(string type, Bug* b);
        // returns the size of the colony
        int size() const;
        // returns true if all the ants in the colony is dead
        bool all_ant_dead() const;
        // returns true if the bug would colide with another bug or a wall
        bool colide(int x, int y) const;
        // returns true if there is an ant at the given cords
        bool ant_at(int x, int y) const;
        // returns the cords of any ants that surround the given cord 
        // returns the same cords if no ants are found
        pair<int, int> next_to_ant(int x, int y) const;
        // moves all the bugs in the colony
        void move();
        // removes a bug from the vector at the given cord
        void remove_bug_at(pair<int, int> c);
        // steps through a whole cycle, move, starve, breed
        void step();
        // spawns an ant with the distrubution odds of 70% females 29% males and 1% Queen
        void spawn_ant_random(int x, int y);
        // gets the gender of the bug at the given cord
        bool get_gender(int x, int y);
    private:
        vector<pair<string, Bug*>> bugs;
        vector<pair<int, int>> walls;
};
#endif