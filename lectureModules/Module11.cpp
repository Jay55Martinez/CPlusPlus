#include <iostream>
#include <array>
#include <vector>
#define size 3
using namespace std;
/*
Multi-demensional:
2d array is also stored in cotinuguous memory locations.
2nd interger is after 1st integer, and so on
2nd row is after 1st row, and so on (row-major language)
a 2d array is essentially 1d array in memory

3d array is also stored in contiguous memory locations

in multi-demensional vectors,, compiler only guarntees that the elements
of one vector are in contiguous locations. It does not guaranteed that the
vector of vectors will have each vector contiguous to other vectors.

user-defined functions has 3 things:
- declaration, definition, function call

*/

int myFunction(int); //declaration
// int myFunction(void);
// void myFunction(int); //not allowed as overloading

int main() {

    //2d built in array
    /*
    int arr[5][5] ={{1,2,3,4,55}, {6,7,8}};

    for(int i=0;i<5;++i) {
        for(int j=0;j<5;++j)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    for(auto& row : arr) {
        for(auto e : row)
            cout<<e<<" ";
        cout<<endl; 
    }

    for(int i=0;i<5;++i) {
        for(int j=0;j<5;++j)
            cout<<&arr[i][j]<<" ";
        cout<<endl;
    }
    */

    /*
    cout<<arr<<endl;
    cout<<&arr[0][0]<<endl; //start of the array
    cout<<&arr[0][5]<<endl; //start of 2nd row (next address after last element of 1st row)
    cout<<&arr[1][0]<<endl; //start of 2nd row
    */

    //int size = 5;
    /*
    int arr3[3][3][3] = {{1,2,3},{6,7,8},{9,10}};
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            for(int k=0; k<size;k++) {
                cout<<arr3[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    for(auto&& box : arr3) {
        for(auto& row : box) {
            for(auto e : row) {
                cout<<e<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    */

    /*
    vector<vector<int>> vv;
    vector<int> v1 = {1,2,44,55};
    for(int ii=0; ii<5;++ii)
        vv.push_back(v1);
    
    for(auto& row : vv) {
        for(auto e : row)
            cout<<e<<" ";
        cout<<endl;
    }
    */

    int my_var = 100;
    int x = myFunction(my_var);
    cout<<x<<endl;

    return EXIT_SUCCESS;
}

int myFunction(int my_v) {
    my_v++;
    cout<<"I am inside myFunction(int)"<<endl;
    return my_v;
}