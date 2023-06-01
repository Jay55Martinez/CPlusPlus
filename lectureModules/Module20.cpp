#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
/*
STL includes containers, iterators and algorithms (functions)
1. Sequence
- Template based libraries: specify any type.
- Two types of contianers (sequence, associative)
-- Sequence: vector or array (contiguous)
-- list [doubly linked list]: sequential access, forward and backward
-- forward_list (singly linked list): sequential access, one direction only
-- deque (deck, double ended queue)
-- Adapter: container built on top of other containers.
-- Queue (FIFO) first in first out
-- Stack (FILO, LIFO)
2. Associative:
-- pair < --- , --- > 
-- map<K,V> : K is keys, and V is values. Keys are unique, stored in sorted manner
-- set<K> : Keys are unique (no duplicates allowed), sorted
-- you also have multiset and multimap
-- C++ offers unordered set and map as well

Most containers have some commin built-in functions. Be sure to check out the documentaion for each
to find out allthe options avaialble.
- size(), empty(), clear(), erase, swap(container), 
- insert(i), insert(i, b, e)
- front(), back(), pop_back() 

-STL Iterators
Most stl algorithms work with iterators connected to a conainer, rather than containers directly. 
and that is the way that c++ has added abstraction.
There are different kinds of iterators:
- input: used by istream, forward-direction only, only read once
- output: used by ostream, foread-direction only, only write once
- forward, bidirectional, random access, contigous (in c++17 onwards)
- IMPORTANT functions related to iterators
-- begin(): returns a reference to the first element of the container
-- end(): returns a reference to the memory location PAST the last element of the container
[b, e) defines the range, read as "begin to past the end"
- Most iterators support operators including ++, --, !=, ->, *, [], +=, >= ect. Be sure to
look at the documentation to see if an operator is supported

STL ALGORITHMS:

*/

struct StudentInfo {
    string name;
    string standing;
    int graduation_year;
};

int main() {
    /*
    cout<<"Vector: "<<endl;
    vector<int> nums1 {1, 2, 3, 4, 5, 6};
    for(auto e : nums1) {
        cout<<e<<" ";
    }
    cout<<endl;

    cout<<"Forward_list: "<<endl;
    forward_list<int> nums2 {nums1.begin(), nums1.end()};
    for(auto e : nums2) {
        cout<<e<<" ";
    }
    cout<<endl;


    cout<<"List: "<<endl;
    list<int> nums3 = {11, 22, 33, 44, 55};
    nums3.reverse();
    for(auto e : nums3) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    cout<<"Queue: "<<endl;
    queue<int> q;
    q.push(1);
    q.push(10);
    q.push(7); // [1, 10, 7]
    q.pop(); //[10, 7]
    cout<<q.front()<<" "<<q.back()<<endl;

    cout<<"Stack: "<<endl;
    stack<int> ss;
    ss.push(50);
    ss.push(10);
    ss.push(22);
    ss.push(11); //[50,10,22,11]
    cout<<ss.top()<<endl; // FILO or LIFO, prints 11, doesn't remove it
    ss.pop(); // removes 11
    cout<<ss.top()<<endl; // FILO or LIFO, prints 22, doesn't remove it
    cout<<ss.size()<<endl; // 3]

    cout<<"Set: "<<endl;
    set<string> states {"CA", "IL", "OH", "FL"};
    states.insert("IN");
    states.insert("NC");
    for(auto p : states) {
        cout<<p<<" ";
    }
    cout<<endl;
    states.insert("FL"); // duplicate was ignored
    auto iter = states.find("AK");
    if(iter == states.end())
        cout<<"not found"<<endl;
    else
        cout<<"fount"<<endl;
    */

    cout<<"Map: "<<endl; //<K,V> are stored in sorted manner
    multimap<string, int> us_states = {{"CA", 1850}, {"OR", 1859}, {"AK", 1959}};
    for(pair<string, int> p : us_states)
        cout<<p.first<<" ("<<p.second<<") "<<endl;
    cout<<endl;
    /* // can use for map 
    us_states["IA"] = 1946; // insert
    us_states["IA"] = 1846; // modify
    for(pair<string, int> p : us_states)
        cout<<p.first<<" ("<<p.second<<") "<<endl;
    cout<<endl;
    */
    pair<string, int> florida = {"FL", 1845};
    us_states.insert(florida); //inserts
    us_states.insert(florida); // no effect
    for(pair<string, int> p : us_states)
        cout<<p.first<<" ("<<p.second<<") "<<endl;
    cout<<endl;
    auto iter1 = us_states.find("FL");
    if(iter1 == us_states.end())
        cout<<"not found"<<endl;
    else
        cout<<"found"<<endl;   


    cout<<endl<<"Containers with customized data"<<endl;
    StudentInfo adeel {"Adeel", "Post-Post_Fraduate", 2027}, amanda {"Amanda", "Senior", 2023};
    map<int, StudentInfo> class_rank;
    class_rank[1] = adeel;
    class_rank[2] = amanda;
    for(auto std_entry : class_rank)
        cout<<"Rank: "<<std_entry.first<<" Name: "<<std_entry.second.name<<endl;
    cout<<endl;

    cout<<"Container of a Container"<<endl;
    map<string, vector<int>> student_grades;
    student_grades["Adeel"] = {63, 33, 100};
    student_grades["Bill"] = {90, 23, 85};
    student_grades["John"] = {13, 35, 64};
    for(auto std_entry : student_grades) {
        cout<<std_entry.first<<": ";
        for(auto gr : std_entry.second) 
            cout<<gr<<" ";
        cout<<endl;
    }

    cout<<endl<<"Map of a Map"<<endl;
    map<int, map<string, int>> numbs;
    numbs.insert(make_pair(1, map<string, int>()));
    numbs[1].insert(make_pair("Amy", 19));
    numbs.insert(make_pair(2, map<string, int>()));
    numbs[2].insert(make_pair("Jay", 20));
    for(auto numbs_entry : numbs) {
        cout<<numbs_entry.first<<" : ";
        for(auto n : numbs_entry.second)        
            cout<<n.first<<" "<<n.second;
        cout<<endl;
    }
    return 0;
}