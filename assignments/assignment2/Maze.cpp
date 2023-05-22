// Jay Martinez -- Assignment2 Generating Maze -- 5/22/23
// Main file for Maze program generates two mazes and prints them
#include <iostream>
#include "MazeHeader.hpp"
using namespace std;

int main() {
    // maze 1
    MazeGenerator m1;
    m1.row = 10;
    m1.col = 8;
    m1.init();
    m1.generate_maze();
    m1.print();

    cout<<endl;
    // maze 2
    MazeGenerator m2;
    m2.row = 50;
    m2.col = 50;
    m2.init();
    m2.generate_maze();
    m2.print();
}