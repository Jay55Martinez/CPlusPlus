#include <iostream>
using namespace std;

namespace std1 {
    void myFunction(int); // by default, pass by value
    void myFunction(const int[]); // by default, pass by ref
    // void myFunction(const int my_val[][20][30]); //by default, pass by ref
    // void myFunction(vector<int>); // by default, pass by value
    // void myFunction(vector<vector<int>>); //by default, pass by value
    // void myFunction(vector<int>&); // by default, pass by ref
    // void myFunction(vector<vector<int>>&); // by default, pass by ref
    // void myFunction(string); //by default, pass by value
    // void myFunction(const string); // by default, pass by ref
}

namespace std2 {
    void myFunction(int, string def = "Default"); // by default, pass by value
}