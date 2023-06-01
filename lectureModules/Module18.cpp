#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
/*
Exception Hierarchy in C++
All Exceptions
- logical error (invalid_argument, out_of_range)
- runtime error (range_error, overflow_error, underflow_error)
* Same mechanism as Java

Recommened:
- Catch specific expection first before catching general exception
- Handle the exception

try {

} catch(kind of exception called e)  {
    e.what(); // displays the error message
}

- noexcept asks the compielr to check if the code throws an exception.
*/

// double mpg(double miles, double gallons) noexcept {
double mpg(double miles, double gallons) {
    if(miles <= 0.0)
        throw invalid_argument("miles must be > 0");
    if(gallons <= 0.0)
        throw invalid_argument("gallons must be > 0");
    return miles/gallons;
}

double read_mpg() {
    cout<<"enter miles and gallons:"<<endl;
    double miles, gallons;
    cin>>miles>>gallons;
    if(!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("input error");
    }
    try {
        return mpg(miles, gallons);
    } catch(const invalid_argument &e) {
        cout<<"invalid argument - read_mgp(): "<<e.what()<<endl;
        throw;
    }
    }

int main() {

    try {
    double result = read_mpg();
    cout<<"mpg is "<<result<<endl;
    } catch(const invalid_argument &e) {
        cout<<"invalid argument: "<<e.what()<<endl;
    } catch(const runtime_error &e) {
        cout<<"runtime error message: "<<e.what()<<endl;
    } catch(const exception &e) {
        cout<<"exception: "<<e.what()<<endl;
    } catch(...) {
        cout<<"error"<<endl;
    }

    cout<<"bye"<<endl;
    return 0;
}