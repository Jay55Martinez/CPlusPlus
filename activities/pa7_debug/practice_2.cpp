// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.
// Number of errors/bugs = 10
#include <iostream>
using namespace std;

void display(int Matrix[3][3], int size);

int main() {
    const int size = 3; // Use const keyword to define size
    int Matrix[size][size]; // matrix the right size
    cout << "Enter 9 elements of the matrix:" << endl; // cin used when cout should be
    for (int i = 0; i < size; i++) { // i was not initialized
        for (int j = 0; j < size; j++) {
            cin >> Matrix[i][j]; // Correct the order of indices
        }
    }
    display(Matrix, size); // passing the matrix is same as @matrix
    return 0;
}

void display(int Matrix[3][3], int size) { //double used in the constructor
    for (int i = 0; i < size; i++) { // fixed for loop
        for (int j = 0; j < size; j++) { // fixed for loop
            cout << Matrix[i][j] << ", ";
        }
        cout << endl; // Add missing semicolon
    }
}
