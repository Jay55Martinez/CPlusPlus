// Jay Martinez -- Assignment2 Rolling of Dice -- 5/22/23
// Main file for the DiceRoll program
#include <iostream>
#include <vector>
#include "DiceRollHeader.hpp"
using namespace std;

int main() {
    vector<vector<int>> arr_rolls;
    arr_rolls = dice::roll_two_dice();
    dice::get_stats(arr_rolls);
}