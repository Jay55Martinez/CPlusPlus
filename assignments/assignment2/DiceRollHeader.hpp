// Jay Martinez -- Assignment2 Rolling of Dice -- 5/22/23
// header file for the DiceRoll program contains two functions:
// roll_two_dice : returns the 2d array of 36000 dice rolls
// get_stats : returns the stats for the given 2d array of dice rolls
#include <iostream>
#include <vector>
using namespace std;

namespace dice {
    // returns a 2d array of dice rolls contains 36000 rolls
    vector<vector<int>> roll_two_dice();

    // prints the number of times a dice combination happend and prints the percentage of
    // time a number appeared
    void get_stats(vector<vector<int>>);
}