// Jay Martinez - Activity4 - 5/19/23
// header file for the functions for Activity4
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

namespace act4 {
    vector<vector<double>> file_to_arr2d(string); // takes content of file and puts in 2d array
    vector<vector<vector<double>>> arr2d_to_arr3d(vector<vector<double>>); // takes content of 2d array and creates 3d array
    void file_out(); // returns a new file with the containing sum, 2d array, 3d array
}