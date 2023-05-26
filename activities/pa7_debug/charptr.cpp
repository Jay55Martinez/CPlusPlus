//This program should read any string (including spaces) from the user and print it using a character pointer
//The program is setup to use pointer offset notation to get each character of the string

//Number of bugs/errors : 8
/*
List of Bugs:
include statement wrong
main return type wrong
while loop wrong can't use == opperator with cstring
print statement printed address not character
*/
#include <iostream> // include statement wrong
#include <cstring>
using namespace std;

int main() {
    char s[20];
    char* cPtr; // pointer not initialized correctly
    cin >> s;
    cPtr = s;
    while (*cPtr != '\0') { // while loop did not work
        cout << *cPtr++; // print statement error
    }
    cout << "\n";

    return 0;
}
