#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
/*
STL ALGORITHMS: 3rd major component <algorithm>
* Key to remember is that algorithms work with iterator. Abstraction allows you to use any underlying
data-structure.
Tow kinds:
- nonmodifying algorithm:
-- count(b, e, val)
-- for_each(b, e, func)
-- find(b, e, val)
-- search(b, e, b2, e2) - 1st occurence of [b2, e2]
- modifying algorihtm:
-- replace(b, e, val, val2)
-- fill(b, e, val)
-- copy()
-- remove()
Review: https://cplusplus.com/reference/algorithm/
*/

bool is_even(int x) {
    if(x%2 == 0)
        return true;
    return false;
}

void print(int x) {
    cout<<x<<" ";
}

void prints(string s) {
    cout<<s<<" ";
}

int sort_desc(string a, string b) {
    return a>b;
}

int ssort_desc(string a, string b) {
    return a.length()<b.length();
}
int main() {
    /*
    cout<<"Find uses linear search - linear time O(n)"<<endl;
    vector<int> c = {9, 5, 7, 2, 7, 2, 3, 6, 2, 5};
    for(auto e : c)
        cout<<e<<" ";
    cout<<endl;
    auto it = find(c.begin(), c.end(), 3);
    if(it != c.end()) {
        cout<<"found"<<endl;
    }
    else
        cout<<"not found"<<endl;
    cout<<*it<<endl;

    // some containers have more efficient version of search available
    set<int> cc = {6, 7, 4, 8, 2, 5, 6, 2, 1, 5, 8};
    for(auto e : cc)
        cout<<e<<" ";
    cout<<endl;
    auto it1 = cc.find(4);
    if(it1 != cc.end())
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl;
    cout<<*it1<<endl;
    */
    /*
    cout<<"find_if uses linear search - linear time O(n)"<<endl;
    vector<int> c = {9, 5, 7, 2, 7, 2, 3, 6, 2, 5};
    for(auto e : c)
        cout<<e<<" ";
    cout<<endl;
    auto it = find_if(c.begin(), c.end(), is_even);
    if(it != c.end()) {
        cout<<"found"<<endl;
    }
    else
        cout<<"not found"<<endl;
    cout<<*it<<endl;

    for_each(c.begin(), c.end()-3, print);
    cout<<endl;

    vector<string> sv = {"Hi", "Hello", "Bye", "GOOD"};
    for_each(sv.begin(), sv.end(), prints);
    cout<<endl;
    */
    /*
    vector<int> c = {9, 5, 7, 2, 7, 2, 3, 6, 2, 5};
    for_each(c.begin(), c.end(), print);
    cout<<endl;
    auto it = remove(c.begin(), c.end(), 5);
    c.erase(it, c.end());
    for_each(c.begin(), c.end(), print);
    cout<<endl;
    */

    vector<string> c = {"grace", "sam", "ada", "steve", "liam"};
    for_each(c.begin(), c.end(), prints);
    cout<<endl;
    sort(c.begin(), c.end(), sort_desc);
    for_each(c.begin(), c.end(), prints);
    cout<<endl;
    return 0;
}