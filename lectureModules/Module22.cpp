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
Priority Queue - is not a queue
Works based on priority (define some mechanism of comparison)
max-heap has max at the top
Max-heap property: the values of each node is less than or equal to the value of its parent
How to implement min-heap
crud approch: multiple each value
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

struct compare { // function object
    bool operator() (const int& left, const int& right) {
        return left<right;
    }
};
struct Point {
    int x;
    bool operator< (const Point& second) const {
        return x > second.x;
    }
};
struct pcompare {
    bool operator() (const Point& left, const Point& right) {
        return left.x > right.x;
    }
};

int main() {   
    /*
    int arr[] = {25, 7, 9, 15, 20, 36, 50};
    // priority_queue<int> pq;
    // priority_queue<int, vector<int>, greater<int>> pq; //min_heap
    priority_queue<int, vector<int>, compare> pq; //max-heap
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
    }
    while(!pq.empty()) {
        cout<<(pq.top())<<" ";
        pq.pop();
    }
    */
    Point arr[] = {{25}, {7}, {9}, {15}, {20}, {36}, {50}};
    // priority_queue<int> pq;
    // priority_queue<int, vector<int>, greater<int>> pq; //min_heap
    // priority_queue<Point> pq; //max-heap
    priority_queue<Point, vector<Point>, pcompare> pq; //min_heap
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
    }
    while(!pq.empty()) {
        cout<<(pq.top().x)<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}