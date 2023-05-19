// Jay Martinez - Activity 3 - 5/19/23
// Main file 
#include <iostream>
#include "Activity3Header.hpp"
using namespace std;

int main() {
    // creating two Dog objects
    Dog d1;
    d1.name = "Spot";
    d1.set_age(3);

    Dog d2;
    d2.name = "Tucker";
    d2.set_age(6);

    // printing the test
    d1.test();
    cout<<endl;
    d2.test();
}