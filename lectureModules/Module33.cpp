#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Templates are used at compile time based on what compiler/assember sees as the usage of the code
(i.e., specific types). They are helpful in optimization and efficiency.
Most of the templates-based code is written in geader-only libraries.
In old times, you would need to run the code to find out if there is any problem in you template based
implementation. Now the fouce of C++ standard 20 on-wards has shifted to compile time error checking.

*/

struct Point2D { 
    int x, y; 
    bool operator== (Point2D pt) {
        return pt.x == x && pt.y == y;
    }
};

bool contains(const int* arr, size_t size, int value) {
    cout<<"int version"<<endl;
    for(size_t ii=0; ii<size; ii++) {
        if(arr[ii]==value)
            return true;
    }
    return false;
}


// bool contains(const double* arr, size_t size, double value) {
//     cout<<"double version"<<endl;
//     for(size_t ii=0; ii<size; ii++) {
//         if(arr[ii]==value)
//             return true;
//     }
//     return false;
// }

template <typename T> 
bool contains(const T* arr, size_t size, T value) {
    cout<<"template version"<<endl;
    for(size_t ii=0; ii<size; ii++) {
        if(arr[ii]==value)
            return true;
    }
    return false;
}

template <class T>
bool contains(const vector<T> vec, T value) {
    cout<<"Vector template version"<<endl;
    for(T e: vec) {
        if(e==value)
            return true;
    }
    return false;
}

int main(void) {
    cout<<"Start"<<endl;
    cout<<boolalpha<<endl;
    const size_t size = 5;
    int arri[size] = {11, 22, 33, 46, 73};
    cout<<contains(arri, size, 11)<<endl;
    double arrd[size] = {11.1, 22.2, 445.2, 43.2, 467.0};
    cout<<contains(arrd, size, 11.1)<<endl;

    vector<int> vi = {11, 22, 33, 44, 55};
    cout<<contains(vi, 33)<<endl;

    vector<string> vs = {"hi", "shi", "fun", "bye"};
    cout<<contains(vs, string("hi"))<<endl;

    vector<Point2D> v2d = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    cout<<contains(v2d, {2, 2})<<endl;
    cout<<"End"<<endl;
    return 0;
}