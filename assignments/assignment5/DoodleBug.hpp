// Jay Martinez -- Assignment 5 -- 6/10/23
/*
class DoodleBug - extends Bug : class represents the doodlebug which is the 
preditor of the ants
members:
int last_eaten : example last_eaten = 3 means that the doodlebug has not eaten in 3 turns
int survive_time : the number of cycles that the bug has survived

constructor:
DoodleBug(int x, int y) : constructor for the doodlebug

functions: 

functions overwriten:
+ void move(Colony* c) : moves the bug to a random tile that is one space away.
If the bug tries to move to where a wall would be they bounce off it. Also bugs can't move
on top of each other.
+ void starve(bool eaten, Colony* c) : removes the bug from memory when it passes a condition is true or given bool is true
+ void breed(Colony* c) : if breed conditions are true adds Bugs to Colony

parent functions:
+ void draw() const : draws the bug
+ void undraw() const : undraws the bug
+ pair<int, int> get_cord() const : gets the x, y cords of the bug
+ char get_symbol() const : gets the symbol of the bug
+ bool get_sex() const : gets the sex of the bug true = female / false = male
+ set_cord(int x, inty) : setter function for cord.
*/
#include "Bug.hpp"

class DoodleBug : public Bug {
    public:
        // constructor
        DoodleBug(int x, int y);
        virtual void move(Colony* c) override;
        virtual void starve(bool eaten, Colony* c) override;
        virtual void breed(Colony* c) override;
    private:
        int last_eaten; // # of turns since it ate a ant
        int survive_time; // # of turns the bug survived
};