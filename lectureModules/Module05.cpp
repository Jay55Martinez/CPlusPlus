#include <iostream>
using namespace std;

int main() {

    // srand(time(nullptr));
    // for(int i=0; i<25; i++) {
    //     for(int j=0; j<25; j++) 
    //         cout<<rand()%10<<" ";
    //     cout<<endl;
    // }

    // switch statement example
    char cc;
    cin>>cc;
    switch(cc) {
        case 'a' : cout<<"a"<<endl; break;
        case 'A' : cout<<"A"<<endl; break;
        case 'B' : cout<<"B"<<endl; break;
        default : cout<<"other"<<endl;
    }

    //you can make complex conditions using AND(&&), OR(||), NOT(!) - Logical
    //bit-wise versions (&, |, ^(XOR), ~)
    //ip1 ip2 output=ip1&&ip2 (AND)
    // 0 0 0
    // 0 1 0
    // 1. 0 0
    // 1. 1 1
    // OR || (inclusive)
    // ip1 ip2 output=ip1||ip2
    // 0 0 0
    // 0 1 1
    // 1. 0 1
    // 1. 1 1
    // XOR ^
    // ip1 ip2 output
    // 0 0 0
    // 0 1 1
    // 1. 0 1
    // 1. 1 0
    // C++ has short circuit evaluation.
    // overallcond = cond1 && cond2 && cond3 && cond4 ....
    // overallcond = cond1 || cond2 || cond3 || cond4 ....

    //for loop with multiple variables
    // for(int l = 10, m = 5; l > 0 && m > 0; l--, m--) {
    //     cout<< l <<" ";
    // }
    // cout<<endl;


    // string str ("Test string");
    // for(auto oneChar : str) // auto means, ask the compiler to figure ut the type
    //     cout << oneChar << ",";
    // cout<<endl;

    // for(int i = 10; i > 0; i--) {
    //     cout<< i <<" ";
    // }
    // cout<<endl;

    string str1 ("a"), str2 {"A"};
    if(str1 < str2)
        cout<<"before - alphabetically"<<endl;
    else if(str1 > str2)
        cout<<"after - alphabetically"<<endl;
    else if (str1 == str2)
        cout<<"equal"<<endl;

    cout<<str1.compare(str2)<<endl;

    //C++ offers a new type of variable - reference variables.
    int i = 100;
    cout<<"address:"<<&i<<", value: "<<i<<endl;
    int &y = i; //y is my reference variable, alias for
    cout<<"address:"<<&y<<", value: "<<y<<endl;
    y=200;
    cout<<"address:"<<&i<<", value: "<<i<<endl;
    //pointer is a variable that stores someone's address
    int* ptr_i = &i;
    cout<<"address:"<<&i<<", value: "<<i<<endl;
    cout<<"address:"<<ptr_i<<", value: "<<*ptr_i<<endl;

}