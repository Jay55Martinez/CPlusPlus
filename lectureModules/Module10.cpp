#include <iostream>
#include <bitset>
#include <limits>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <array>
using namespace std;

/*
 Variables: 
 - automatic scope (created when you enter the scope and declare the, and compilers
 deletes them when they go out of scope), default!
 - static scope: created at compile time, stay alive till end of the program. this is
 beyond scope of a block

 Arrays - how things look in memory
 - Built-in arrays are NOT initailzied by compiler. It is the programmers responsilibity.
 - Indices start at 0.
 - C++ guarantees that elements of built-in array are stored in CONTIGUOUS meory locations.
 --> In memory [1][2][3][4][5], each [] is one integer.
 - It is programmer's responsibility to make sure that indices are valid. In C++, you will NOT
 get a warning or an exception of you indices are wrong.
 --> This is the biggest source of trouble -> buffer overflow
 
 Pointer variables store memory address
 Increamenting pointer variables is equivalent to going to the next variable in memory
 which might vary depending on the type of pointer,
 ptr++ for int means increment address by 4B and ptr++ for double means incremenent address
 by 8B
 Don't try this for char* (because C++ handles char ptr differently, c-string)

 C++ offers a rich list of containers as part of STL. array and vectors

*/

int main() {
    /*
    int x = 1; //automatic scope (in C, means "auto" but not in C++)
    auto y = 1; //auto in C+ means ask the compiler to decide the type of variable
    cout<<sizeof(y)<<" "<<typeid(x).name()<<endl;

    const int z = 1; // const - read only like (final in java)
    // z += 5; this is not allowed
    cout<<z<<endl;
    */

    //Built-in arrays
    // in memory [1][2][3][4][5], each is one integer
    int arr[5] = {1,2,3,4,5}; //int arr[5] = {};
    // int arr[5] = {}; // all five integers are initialized to zero
    // int arr[6] = {1,2,3,4,5,6}; //compiler creates an array if 6 ints
    
    for(int i=0; i<=5; i++) { // indices are 0,1,2,3,4
        cout<<arr[i]<<endl;
    }

    for(int e : arr) { // no indices in this version, e is value
        cout<<e<<" ";
    }
    cout<<endl;

    for(auto e : arr) { // no indices in this version, e is value
        cout<<e<<" ";
    }
    cout<<endl;

    cout<<arr<<" "<<&arr<<" "<<&arr[0]<<endl; 
    cout<<&arr[1]<<" "<<&arr[2]<<" "<<&arr[4]<<" "<<&arr[5]<<endl;
    // arr and &arr are addresses of first int (one int)
    // &&arr is the address of the beginning of the array of integers (many integers)
    // notice that elements are stored in continguous locations!

    
    //double arrd[5] = {1.1,2.2,3.3,4.4,5.5};
    /*
    for(auto e : arrd) {
        cout<<e<<" ";
    }
    cout<<endl;
    cout<<arrd<<" "<<&arrd<<" "<<&arrd[0]<<endl<<&arrd[1]<<" "<<&arrd[4]<<" "<<&arrd[5]<<endl;
    // double takes 8 bytes, stored contiguously
    */
    /*
    // pointer variables store memory addresses
    int * ptr1 = arr;
    cout<<ptr1<<endl;
    cout<<ptr1+1<<endl; // value of next integer address <=> address of next integer

    double * ptr2 = arrd;
    cout<<ptr2<<endl;
    cout<<ptr2+1<<endl; // value of next doubel address <=> address of next integer

    int p = 100;
    cout<<p<<endl;
    cout<<p+1<<endl;
    */

    array<int, 7> arr1 = {1,2,3,4,66};
    cout<<"Size "<<arr1.size()<<endl;
    vector<int> v1 = {1,2,3,4,66};
    cout<<"Size "<<v1.size()<<endl;

    vector<int> v2; //vector of size 0
    cout<<"Size "<<v2.size()<<endl;
    v2.push_back(30+arr1[0]);
    v2.push_back(30+arr1[1]);
    v2.push_back(30+arr1[2]);
    v2.push_back(30+arr1[3]);
    v2.push_back(30+arr1[4]);
    cout<<"Size "<<v2.size()<<endl;
    for(auto e : arr1)
        cout<<e<<" ";
    cout<<endl;
    for(auto e : v2)
        cout<<e<<" ";
    cout<<endl;


    return EXIT_SUCCESS;
}