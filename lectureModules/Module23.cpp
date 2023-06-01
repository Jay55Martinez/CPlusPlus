#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Function Objects can be called like a function. They often have operator() inplemented.
Lambda Expressions: use them when we want to creat a function object on the fly ("use and discard")
NOTE: They can also capture pieces of environment using []

Here is what a typical lamda func def looks like:
example:
bool someFunction (int x) { return x + 2; }

bool ... (int x) { implementation; }

[] (int x) -> bool { implementation; }
here [] means no captures, int argument, bool return type

[] (int x) { implementation; }
let compiler figure out return type

auto fn = [] (int x) { implementation; }
give it a name, called a lamda fn

Examples:
auto fn = [] (int x) { return x<3; } // lt_three
auto fn = [] (int x) { return x<5; } // lt_five

Lamda expressions can use captures, which is variables from the local envirment
[] capture nothing
[&] capture any external variable by refference
[=] capture any external variable by making a copy
[var] capture the named var by making a copy
[=,&var]  capture any external var by reffernce and copy
*/

void print(int x) {cout<<x<<" ";}
bool lt_three(int x) {return x<3;}
bool lt_five(int x) {return x<5;}

struct LessThan {
    int value; // this is state
    bool operator() (int x) {
        return x < value;
    }
};

int main() {
    /*
    vector<int> c = {3, 5, 6, 15, 52, 53, 43, 3};
    for_each(c.begin(), c.end(), print);
    cout<<endl;
    // cout<<count(c.begin(), c.end(), 3)<<endl;
    // cout<<count_if(c.begin(), c.end(), lt_five)<<endl;
    // cout<<count_if(c.begin(), c.end(), lt_five)<<endl;
    // LessThan lt3{3};
    // cout<<lt3(2)<<endl;
    // LessThan lt5{5};
    // cout<<lt5(2)<<endl;
    auto fn = [] (int x) { return x<5; }; // lt_five
    cout<<count_if(c.begin(), c.end(), fn)<<endl;
    cout<<count_if(c.begin(), c.end(), [] (int x) {return x<5};)<<endl;
    // cout<<count_if(c.begin(), c.end(), LessThan{5})<<endl;
    */

    int accum = 0;
    auto fnn = [&accum] (int x) { accum+=x; };
    vector<int> c = {3, 5, 6, 15, 52, 53, 43, 3};
    for_each(c.begin(), c.end(), print);
    cout<<endl;
    cout<<"Before: "<<accum<<endl;
    for_each(c.begin(), c.end(), fnn);
    cout<<"After: "<<accum<<endl;
    return 0;
}