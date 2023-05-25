#include <iostream>
#include <cstring>
using namespace std;

/*
what do we know:
- cstring: character array with a special null character ar the end. User is repsonsible for
  for '/0' most of the time. ASCII code 0. (false in conditional statement) Computational faster
  than its alternative (i.e., string in C++).
  <cstring> library with related functions.
- Pointer Variables: store memory addresses. int ptr will have int address (you can find with &
  operator). The contents of a ptr are "address" but the value at that address can be accessed
  using * (dereferencing)
- & operator is not allowed for chars. Instead we use a char*
- Name of the array is the address for the first element of the array
// WARNING: PROGRAMMER IS RESPONSIBLE FOR NULL CHARACTER. IF YOU OVERWRITE IT, YOU WILL BE IN
// TROUBLE
// Assignment operations does not work with cstring
// Equality operator(==) is not gaurented to work with cstrings
// You can use cin and cout to io your cstring
// Be careful using cin because there is no way to know when the user stops entering input
   Alternative is to use cin.getline() where you specify number of chars to read
// Most cstring library functions expect null character to be present!

*/

int main() {
    /*
    char greeting1[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // H E L L O \0
    char greeting2[] = "Hello"; // compiler adds null char at the end // H E L L O \0
    char greeting3[15] = "Hello"; // H E L L O \0 \0 \0 ... \0
    char greeting4[15] = ""; // string literal
    char greeting5[15] = {0}; // ascii code 0 - null
    char greeting6[15] = {'\0'}; // ascii code 0 - null
    */
    //WARNING: PROGRAMMER IS RESPONSIBLE FOR NULL CHARACTER. IF YOU OVERWRITE IT, YOU WILL BE IN
    //TROUBLE

    // cout<<greeting1<<endl;
    // cin>>greeting1;
    // cout<<greeting1<<endl;

    // char greeting[] = "What's up"; // works
    // char greeting[15];
    // greeting = "What's up"; // not allowed
    /*
    strcpy(greeting, "What's up");

    cout<<greeting<<endl;
    */
    // if(greeting == "What's up") // not gauranteed to work
    /*
    if(!strcmp(greeting, "What's up"))
        cout<<"equal"<<endl;
    else 
        cout<<"noe equal"<<endl;
    */
    /*
    int x = 5;
    char str[8] = "";
    int y = 10;
    cout<<&x<<" "<<&str<<" "<<&y<<endl;
    cout<<x<<","<<y<<endl;
    //cin>>str;
    cin.getline(str, 8); // use this to take in characters bc you can specify amout of chr in
    cout<<str<<endl;
    cout<<x<<","<<y<<endl;
    */
    /*
    char str[] = "WhatNow?";
    str[8] = 'A'; //overwrote null character
    int i = 0;
    while(str[i] != '\0') {
        cout<<str[i]<<" "<<static_cast<int>(str[i])<<endl;
        i++;
    }
    cout<<i<<endl;
    */
    
    char cstr[] = "Hello World";
    string cppstr = cstr;
    cout<<cstr<<","<<cppstr<<endl;

    string cppstr2 = "abcdefgh";
    // char cstr2[] = cppstr2.c_str(); // not allowed, use strcpy
    // char cstr2[]; strcpy(cstr2, cppstr2.c_str()); // would work but size not specifed
    const char* cstr2 = cppstr2.c_str();
    cout<<cstr2<<","<<cppstr2<<endl;
    
    return EXIT_SUCCESS;
}