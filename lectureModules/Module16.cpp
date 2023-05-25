#include <iostream>
#include <cstring>
using namespace std;
/*
Pointers and Structures:
-- Structures can be used to build powerful data structures.
-- Mumbers of structure are by default public
-- Members can be variables (in C, only variables), and functions (int C++, variables and functions)
-- A function followed by a const key word is not allowed to modify members of the structure
//RULE: EVERY POINTER MUST POINT TO VALID LOCATION
assignment opperators don't work with cstring
== opperator does not work with structs unless defined
// The size of structure instance might be bigger than sum of sizes of members dur to "memory holes"
// This is because compiler tries to allocate new variables at word (or double word) boundaries (starting ar 4 bytes
addresses) - new vars are created at addresses that are divisible by 8.
[int=4+4B hole][string=24][char 1+7Bytes of hole][char*=8]
-- You can create a structure that is a member of another structure (structure inside another structure)
(structure can't have itself as its member but a structure can have a pointer to itself as a member)
-- You can pass a structure instance to a function. Default is pass by value. You can also pass a
structure by reference. You can also return a structure instance from a function.
-- You can also create a vector of structure instances 
*/
struct Student {
    int std_id;
    string std_name;
    //char std_data[20];
    char* std_gender;
    char std_grade;
    // defined in-line : when diffined in the struct
    void print() const {
        cout<<std_id<<":"<<std_name<<endl;
        //std_name += "A"; //can't modify members of the structure
    }
    bool operator==(const Student &other) const {
        return std_name == other.std_name && std_id == other.std_id;// && !strcmp(std_data, other.std_data);
    }
} std2 {23, "Anna"}, *ptr_std2= &std2, many[20]= {std2, std2, std2};
// } std2 {23, "Anna", "C++"}, *ptr_std2= &std2, many[20]= {std2, std2, std2};

struct CS3520Section {
    int code;
    Student roster[75];
    // ...
};

int main() {
    std2.print();
    ptr_std2->print();
    //strcpy(std2.std_data, "Programming in C++");
    //std2.std_data = "Programming in C++"; // Does not work with cstrings
    ptr_std2->print();
    (*ptr_std2).print();
    //std2->print(); // -> only works with pointer
    many[1].print();

    if(many[1] == many[0]) 
        cout<<"equal"<<endl;
    else 
        cout<<"not equal"<<endl;

    cout<<"size1: "<<sizeof(std2)<<endl;
    cout<<"size2: "<<sizeof(int)+sizeof(string)+sizeof(char)+sizeof(char*)<<endl;

    std2.std_gender = "female";
    cout<<ptr_std2->std_gender<<endl;

    Student* ptr_std1 = new Student({20, "Harry"});
    ptr_std1->print();
    delete(ptr_std1);
    ptr_std1->print();

    CS3520Section summ2023, *ptr_su23 = &summ2023;
    cout<<summ2023.roster[0].std_id<<endl;
    return 0;
}