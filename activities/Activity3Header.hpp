// Jay Martinez - Activity 3 - 5/19/23
// Header file for the Dog class
// Dog class stores information about the dog
#ifndef DOG_H
#define DOG_H

#include <iostream>
using  namespace std;

class Dog {
    public:
        string name;
        static int num_legs;
        void set_age(int); // sets the age of the dog
        void test(); // returns the memory address and values of variables 
    private:
        static bool friendly;
        int age;
};

#endif