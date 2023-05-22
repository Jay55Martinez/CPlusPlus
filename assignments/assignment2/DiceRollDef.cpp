// Jay Martinez -- Asignment2 Rolling of Dice -- 5/22/23
// Definitions of the functions declaired in the header file
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include "DiceRollHeader.hpp"
using namespace std;

namespace dice {
    /*
    pseudocode for roll_two_dice:

    set rand seed (time)
    int d
    vector<vector<int>> arr_rolls
    vector<int> roll
    for (i = 0; i < 36000; i++) {
        for (j = 0; i < 2; j++) {
            d = rand() % 6 + 1
            roll.pushback(d);
        }
        arr_rolls.pushback(roll);
        roll.clear();
    }
    */
    vector<vector<int>> roll_two_dice() {
        srand(time(NULL)); // set random seed
        // variables decleration
        vector<vector<int>> arr_rolls;
        vector<int> roll;
        int d;

        // creates 2d array full of dice rolls
        for(int i=0; i<36000; i++) {
            for(int j=0; j<2; j++) {
                d = rand() % 6 + 1; // random value btw 1 - 6
                roll.push_back(d);
            }
            arr_rolls.push_back(roll);
            roll.clear();
        }

        // print the values in the array
        /*
        for(int i=0; i<36000; i++) {
            for(int j=0; j<2; j++) 
                cout<<arr_rolls[i][j]<<" ";
            cout<<endl;
        }
        */
        return arr_rolls;
    }

    /*
    pseudocode for get_stats:

    vector<vector<int>> arr_combinations;
       1 2 3 4 5 6 d2
    1 [0 0 0 0 0 0]
    2 [0 0 0 0 0 0]
    3 [0 0 0 0 0 0]
    4 [0 0 0 0 0 0]
    5 [0 0 0 0 0 0]
    6 [0 0 0 0 0 0]
    d1
    int d1;
    int d2;
    for (i = 0; i < 3600; i++) {
        for(j - 0; j < 2; j++) {
            if(j = 0)
            di = arr_rolls[i][j];
            else
            d2 = arr_rolls[i][j];
        }
        arr_combinations[d1-1][d2-1] = arr_combinations[d1-1][d2-1] + 1;
    }
    for(i = 0, i < 6, i++) {
        for(j = 0, j < 6, j++) {
            time_rolled = arr_combinations[i][j];
            print (the dice combination i and j rolled:# time \n)
            percentage = arr_combinations[i][j];
            print (the percentage that i and j were rolled was #)
        }
    }
    */
    void get_stats(vector<vector<int>> arr_rolls) {
        // array of possible combinations of rolls initailized with all 0s
        vector<vector<int>> arr_combinations(6, vector<int>(6, 0));

        // count the total values 1 - 12 
        vector<int> arr_values(12);
        int d1;
        int d2;
        // fill combination array with data
        for(int i=0; i<36000; i++) {
            for(int j=0; j<2; j++) {
                if(j == 0)
                    d1 = arr_rolls[i][j];
                else
                    d2 = arr_rolls[i][j];
            }
            arr_combinations[d1 - 1][d2 -1] += 1;
            arr_values[d1 + d2 - 1] += 1;
        }

        // prints the data
        for(int i=0; i<6; i++) {
            for(int j=0; j<6; j++) {
                cout<<"The dice combination "<<i + 1<<" and "<<j + 1
                <<" was rolled: "<<arr_combinations[i][j]<<" times"<<endl;
                cout<<"the percentage that "<<i + 1<<" and "<<j + 1
                <<" was rolled %"<<(double)arr_combinations[i][j]/36000<<endl;
            }
            cout<<endl;
        }

        // print the number of time each value was rolled
        for(int i=1; i<12; i++) {
            cout<<"The value "<<i+1<<" was rolled "<<arr_values[i]<<" times"<<endl;
        }
    }
}