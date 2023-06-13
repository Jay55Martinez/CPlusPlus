// Jay Martinez -- Assignment 5 -- 6/10/23
/*
class Ant - extends Bug class : class represents a Ant that will
members: 
int last_moved : each turn the ant does not this value increases

constructor:
Ant(int x, int y, bool sx) : constructor for the ant class

functions: 


functions overwriten:
+ void starve(bool eaten, Colony* c) : removes the bug from memory when it passes a condition is true or given bool is true
+ void breed(Colony* c) : if breed conditions are true adds Bugs to Colony
+ void move(Colony* c) : moves the bug to a random tile that is one space away.
If the bug tries to move to where a wall would be they bounce off it. Also bugs can't move
on top of each other

parent function : 
+ void draw() const : draws the bug
+ void undraw() const : undraws the bug
+ pair<int, int> get_cord() const : gets the x, y cords of the bug
+ char get_symbol() const : gets the symbol of the bug
+ bool get_sex() const : gets the sex of the bug true = female / false = male
+ void set_cord() : sets the cords 
*/
#include "Bug.hpp"

class Ant : public Bug {
    public:
        Ant(int x, int y, bool sx);
        virtual void move(Colony* c) override;
        virtual void breed(Colony* c) override;
        virtual void starve(bool eaten, Colony* c) override;
    private:
        int last_moved; 
};