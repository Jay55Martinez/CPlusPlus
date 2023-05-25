#include <iostream>
#include <cstring>
using namespace std;

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

// C++ offers you the ablity to control values of variables to the bit level
struct abc1{int a, b; char c;} xx1;
struct abc2{int a:24, b:2; char c;} xx2;
struct abc3{int a:24,  :0, b:2, :0; char c, :0;} xx3;

//union is often used when you need to presever memory
//it allocate memory equivalent to the size of largest member only and all members share the same
// memory. The member with most recent update will have correct value
//union int_or_double {int i; double d;}; // this size of this union is 8Bytes size of double
typedef union int_or_double {int i; double d;} number;

// default is count starts at 0
enum class Direction {north, south, east, west};
string dir_name(Direction d) {
    switch(d) {
        case Direction::north : return "north";
        case Direction::south : return "south";
        case Direction::east : return "east";
        case Direction::west : return "west";
        defualt: return "ERROR";
    }
}

int main() {
    /*
    Student* one_ptr = new Student{11111, "Someone"};
    cout<<one_ptr->std_name<<endl;

    Student* one_ptr_teninstances = new Student[10];
    cout<<one_ptr_teninstances[0].std_name<<endl;

    Student *ten_ptrs[10] = {new Student{333, "Bob"}, new Student, new Student{444, "Bill"}};
    cout<<ten_ptrs[0]->std_id<<endl;
    cout<<(*ten_ptrs[2]).std_id<<endl;
    */

    /*
    number num1;
    num1.i = 4444;
    cout<<num1.i<<" "<<num1.d<<endl;
    num1.d = 33.512;
    cout<<num1.i<<" "<<num1.d<<endl;

    int_or_double another;
    cout<<"size of union: "<<sizeof(another)<<endl;
    */

    //cout<<sizeof(xx1)<<" "<<sizeof(xx2)<<" "<<sizeof(xx3)<<endl;

    Direction d1 = Direction::west;
    cout<<dir_name(d1)<<endl;
    cout<<static_cast<int>(d1)<<endl;
    cout<<dir_name(static_cast<Direction>(0))<<endl;
    return 0;
}