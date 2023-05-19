// Jay Martinez - Activity 3 - 5/19/23
// Definitons for the dog class
#include <iostream>
#include "Activity3Header.hpp"
using namespace std;

// define and initialize static data member at global namespace scope
int Dog::num_legs = 4; 
bool Dog::friendly = true;

// sets the age of the dog
void Dog::set_age(int a) {
    Dog::age = a;
}

// returns memory address of the variables and the variables values
void Dog::test() {
    cout<<"Memory adr num_legs: "<<&num_legs<<endl
        <<"Memory adr friendly: "<<&friendly<<endl
        <<"Memory adr age: "<<&age<<endl
        <<"Memory adr name: "<<&name<<endl
        <<"Value num_legs: "<<num_legs<<endl
        <<"Value friendly: "<<friendly<<endl
        <<"Value age: "<<age<<endl
        <<"Value name: "<<name<<endl;
}