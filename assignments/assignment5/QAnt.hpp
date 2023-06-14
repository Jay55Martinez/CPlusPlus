// Jay Martinez -- Assingment 5 -- 6/13/23
/*
class QAnt : extends Bug - represents a Queen ant

members:
int survive_time;
bool bred;

constructor:
QAnt(int x, int y) : constructor for the ant class

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

class QAnt : public Bug {
    public:
        QAnt(int x, int y);
        virtual void move(Colony* c) override;
        virtual void breed(Colony* c) override;
        virtual void starve(bool eaten, Colony* c) override;
    private:
        int survive_time; 
        bool bred;
};