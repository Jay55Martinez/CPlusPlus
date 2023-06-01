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
int main() {
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

    return 0;
}