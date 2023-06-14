// Jay Martinez -- Assignment 5 -- 6/10/23
/*
class window_s : draws the container for the ants
members:
int upper_left_x :
int upper_left_y :
int width :
int height :
char draw_char :

constructor:
window_s(int x, int y, int w, int h) : sets the upper_left_x = x
, upper_left_y = y, width = w, height = h

functions:
+ void set_char(const char c) : sets the draw_char
+ void draw() const : draws the window using ncurses base on the member variables
+ void set_out_of_bounds() : sets the out of bounds member variable
+ int get_width() const : getter
+ int get_height() const : getter
+ int get_offsetx const : getter
+ int get_offsety const : getter

*/
#include <vector>
#include <utility>
using namespace std;

class window_s {
    public:
    // constructor 
    window_s(int x, int y, int w, int h);
    // setter draw_char
    void set_char(const char c);
    // draw the window 
    void draw() const;
    // sets all of the cords that are out of bounds
    vector<pair<int, int>> get_out_of_bounds() const;
    //getters
    int get_width() const;
    int get_height() const;
    int get_offsetx() const;
    int get_offsety() const;
    
    private:
    int upper_left_x;
    int upper_left_y;
    int width;
    int height;
    char draw_char;
};
