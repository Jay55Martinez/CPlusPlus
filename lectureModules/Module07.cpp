#include <iostream>
using namespace std;

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
        static char std_grade;
        void print();// { cout<<std_name<<" "<<std_id<<endl; } // in-line definition
};

void Teacher::print() { cout<< std_name << " " << std_id << " with grade " << std_grade << endl; }
char Teacher::std_grade = 'A'; // initaized out the member of the class
// Static members belong to the class (not object) and that's why they are accessed using 
// classname rather than object name with ::

int i = 1; //global_scope - accessable anywhere in this file

// C++ Coercion (conversion rules)
/*
C++ uses the following ranking:
1. int -> unsigned int -> long -> unsigned long -> float -> double -> long double
- a comparison between unsigned int and int says that lower ranking type gets converted to higher
ranking type before comparison => i.e., int gets converted to unsigned int
2. char, short, unsigned char -> automatically get promoted to -> int
- if unsigned char > int then unsigned char is promoted to unsigned int 
3. All other: lower ranking -> promoted to -> higher ranking
4. final value get promoted to the type that is being assigned to
- if it is assigned to lower ranking, then data is demoted!

General Recommendation is to avoid operations between differnt types

Proble Solving -> think before you code! (Design before implement)


*/

int main() {

    unsigned int two = 2;
    int minus_two = -2;
    cout<<hex<<two<<endl;
    cout<<hex<<minus_two<<endl;

    if(minus_two < two) {
        cout<<"-2<2"<<endl;
    }
    else 
        cout<<"-2>2"<<endl;

    unsigned int ui = 2;
    int si = -1;
    double d = 3.11;
    char cc = 'A';
    cout<<dec<<ui+si<<endl; //unsigned int
    cout<<d+ui<<endl; // double
    cout<<d+si<<endl; // double
    cc = d+100; // double gets demoted form double to char
    cout<<(int)cc<<" "<<cc<<endl;
    /*
    cout<<"V: "<<i<<" A: "<<&i<<endl;
    // Scope of the variables relates to its life span and where it is accessible
    // Scope is defined by the enclosing braces
    int i = 10; //local_to_main_var
    cout<<"V: "<<i<<" A: "<<&i<<endl;
    {
        int i = 100; //local_to_this_block_inside_main
        cout<<"V: "<< i <<" A: "<< &i<<endl;
    }
    cout<<"V: "<< i <<" A: "<< &i<<endl;
    Student first;
    first.std_id = 100;
    first.std_name = "Jay";
    // cout<<first.std_id<<" "<<first.std_name<<endl;
    first.print();

    Teacher second {15, "John"}, third{111, "Jenna"};
    // cout<<second.std_id<<" "<<second.std_name<<endl;
    second.print();
    third.print();
    */
}