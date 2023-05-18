#include <iostream>
#include "file.hpp"
using namespace std;

/*
Functions:
Pass by value - makes a copy of the variable.
Pass by refernece - does not make a copy
Code Organizatoin:
1. Declaratons go into a separate file (header file *.hpp)
2. main function will go inside a cpp file (driver)
3. definitions go inside a separate cpp file (implementaion)
Your implementation file will #include your header file, so will your driver program
#include "youfile.hpp"
Caution: avoid using multiple includes. To get around it we use GUARD bits
#ifndef MY_TEST
#define MY_TEST
your declarations go here
#endif

Array arguments are passed by reference (default)
You pass the reference of the first element. ARRAY decay -> no notion of size
you have to pass size as an argument as well along with your array.
To restrict a function from modifying an array arguement, use const
In modern C++, use of pass by ref with const is wide spread!!

default arguemnts can be specified in function header/prototype!
*/

// These declarations go in a separate file (header file *.hpp)
// int myFunction(int);
int myFunction(int&);
void print_me(int[], int); // dec - pass array function can modify
void print_me(const int[], int); // dec - pass array function can't modify
void print_me(string = "Hello");
// void print_me(int[][5], int, int); // dec - pass array function can modify
// void print_me(int[][5][5], int, int, int); // dec - pass array function can modify

// the main will go into a separate file (driver file *.cpp)
int main() {
    /*
    int my_var = 100;
    cout<<"Value of my_var in main(): "<<my_var<<" "<<&my_var<<endl;

    myFunction(my_var);
    cout<<"Value of my_var in main(): "<<my_var<<" "<<&my_var<<endl;

    int arr[] = {1,2,3,4,5,6};

    print_me(arr, 6);

    for(auto e : arr)
        cout<<e<<" ";
    cout<<endl;

    print_me();
    print_me("string statement");
    */

    int my_val = 100;
    std1::myFunction(my_val);

    return EXIT_SUCCESS;
}

// definions will go into a seperate file
/*
// pass by value
int myFunction(int my_var) {
    cout<<"Value of my_var in myFunction(int): "<<my_var<<" "<<&my_var<<endl;
    my_var++;
    cout<<"I am inside myFunction(int)"<<endl;
    return my_var;
}
*/

// pass by reference
int myFunction(int& my_var) {
    cout<<"Value of my_var in myFunction(&): "<<my_var<<" "<<&my_var<<endl;
    my_var++;
    cout<<"I am inside myFunction(&)"<<endl;
    return my_var;
}

void print_me(const int arrr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arrr[i]<<",";
        // arrr[i] += 10;
    }
    cout<<endl;
}

void print_me(int arrr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arrr[i]<<",";
        arrr[i] += 10;
    }
    cout<<endl;
}

void print_me(string str) {
    cout<<str<<endl;
}
