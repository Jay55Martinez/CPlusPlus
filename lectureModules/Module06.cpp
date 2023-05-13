#include <iostream>
using namespace std;

/*
-Struct is a way to define new types with multiple variable as memebers (grouping many types
together)
-C style of struct only allows members that are variables
-C++ style of struct allows members to be variables and functions
-members of a struct are "public" by default
-memebers of a class are "private" by default
*/

// c style of struct
struct Student {
    int std_id;
    string std_name;
    void print() {
        cout<<std_name<<" "<<std_id<<endl;
    }
};

class Teacher {
    public:
        int std_id;
        string std_name;
        void print() {
            cout<<std_name<<" "<<std_id<<endl;
        }
};

int main() {
    Student first;
    first.std_id = 100;
    first.std_name = "Jay";
    // cout<<first.std_id<<" "<<first.std_name<<endl;
    first.print();

    Teacher second {15, "John"};
    // cout<<second.std_id<<" "<<second.std_name<<endl;
    second.print();

}