// Jay Martinez -- Assignment2 Generating Maze -- 5/22/23
// Header file for the MazeGenerator class contains the function:
// generate : makes the maze with the given size of the row and col
// print : prints the maze using '#' as walls and '.' as open spaces
// valid_open_space : determins if the spot can have a open space
#include <iostream>
#include <vector>
using namespace std;

class MazeGenerator {
    public:
    int row;
    int col;
    void generate_maze();
    void init();
    void print();

    private:
    vector<vector<char>> maze;
    bool valid_open_space(int x, int y);
    void generate(int x, int y);
};