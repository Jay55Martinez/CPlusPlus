#include <iostream>
#include <vector>
using namespace std;

struct the_answer{};
void foo1(const the_answer &is) { // 
    cout<<"l_value"<<endl;
}

void foo1(const the_answer &&is) {
    cout<<"r_value"<<endl;
}

void foo2(const the_answer &is, int i) { // 
    cout<<"l_value "<<i<<endl;
}

void foo2(const the_answer &&is, int i) {
    cout<<"r_value "<<i<<endl;
}

template<typename T>
void foo0(T &&t) {
    //foo1(t);
    foo1(forward<T>(t));
}

template<typename... Args>
void foo00(Args &&... args) {
    //foo1(t);
    foo2(forward<Args>(args)...);
    cout<<sizeof...(args)<<endl;
    // get<0>(args); // will get the first argument
    // get<1>(args); // will get teh second argument
}


int main(void) {
    the_answer is;
    foo0(is); // lvalue ref
    foo0(the_answer()); // not rvalue since it is named variable.

    foo00(is, 5);
    foo00(the_answer(), 5);

    return 0;
}