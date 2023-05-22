// Jay Martinez -- Assignment2 Generate Maze -- 5/22/23
// Definition file for MazeGenerator
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "MazeHeader.hpp"
using namespace std;

void MazeGenerator::generate_maze() {
    srand(time(NULL));
    int r = rand() % (col - 2) + 1;  // Randomly select a column for the left '.' (excluding the first and last columns)
    generate(0, r);
    
    r = rand() % (col - 2) + 1;  // Randomly select a column for the right '.' (excluding the first and last columns)
    maze[row - 1][r] = '.';  // Place the right '.' on the bottom row
}

// initialize the maze with all walls
void MazeGenerator::init() {
    // Fills the grid with walls ('#' characters).
    for(int i=0; i<row; i++) {
        vector<char> rowVector;
        for(int j=0; j<col; j++)
            rowVector.push_back('#');
        maze.push_back(rowVector);
    }
}

// generate() initializes the maze vector in the class to be valid
/*
psuedocode for generate():

create arr with 4 directions : up, down, left, right
mix up directions
loop till valid direction:
    update maze
    recure at new cords
*/
void MazeGenerator::generate(int x, int y) {
    maze[x][y] = '.';
    // Generate random directions array
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Randomize the directions
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp[2];
        for(int j=0; j<2; j++) {
            temp[j] = directions[r][j];
            directions[r][j] = directions[i][j];
            directions[i][j] = temp[j];
        }
    }

    // Loop through each direction and attempt to visit that direction
    for (int i = 0; i < 4; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];

        int x2 = x + (dx * 2);
        int y2 = y + (dy * 2);

        if (valid_open_space(x2, y2)) {
            maze[x2][y2] = '.';
            maze[x + dx][y + dy] = '.';
            generate(x2, y2);
        }
    }
}

// NOTE THAT THE MAZE GENERATION IS NOT PERFECT AND HAS TO DO WITH THIS
// checks if the space give is valid
bool MazeGenerator::valid_open_space(int x, int y) {
    // Returns "true" if x and y are both in-bounds. 
    return (x > 0 && x < row - 1 && y > 0 && y < col && maze[x][y] == '#');
}

// prints the maze
void MazeGenerator::print() {
    // loops through the vector and prints the char
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++)
            cout<<MazeGenerator::maze[i][j]<<" ";
        cout<<endl;
    }
}