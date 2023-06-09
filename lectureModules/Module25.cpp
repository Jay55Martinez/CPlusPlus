#include <iostream>
using namespace std;

/*
struct DayOfTheYear {
    int month, day;
    void output() const{ cout<<month<<"/"<<day<<endl; }
};
*/

/*
Deconstructors:
- Destructors are also public function. they are all called when the object goes out of scope. They
are called in reverse order 
- Destructors are not called when malloc and free are used.
- Destructors are not call when program throws an error or exception. they are called if an exception is caught
- pass by value calls the destructor again
Friend Functions:
- General guideline all members should be private
- A Friend Function is a non-member function of a class. This is special because it has access to private members of the class.
To declare a Friend function you write the function decleration inside the classs. You then define that function outside the class.
(without using scope operator). You can access private members with the dot operator.
Operator Overloading:
- operator==
- can't overload sizeof operator, typeid, scoperesolution(::), class member access (.), tenerary ?:
- can't change precendence or assicativity or -arity [binary/unary] of operators
- Only overload existing operators, can't make new operator
- Overloading (), [], ->, or = must be declared as a member of a class
- Example
General style of operating overloading:
-- there are two kind of operators binary and unary
-- unary operator needs one value. friend version needs one argument, member version needs zero arguments
-- binary operator needs two values friend version will need two arguments, and member version will need one argument
the second being member of the class. Return sum of two operands in a new variable. don't change values of the argument
Binary + Version - Friend version: resultValue operator+  (const left_operand, const right_operand)
Binary + Version - Member version: resultValue operator+ (const one_operand) const
-- unary
Unary + Version - Friend version: resultValue operator+  (const one_operand)
Unary + Version - Member version: resultValue operator+ () const


*/
class DayOfTheYear {
    private:
        int month, day;
    public:
        DayOfTheYear() { cout<<"default constructor"<<endl; this->month = 0; this->day = 0; }
        DayOfTheYear(int m, int n) { cout<<"overloaded constructor"<<endl; (*this).month = m; (*this).day = n; }
        ~DayOfTheYear() { cout<<"deconstructor"<<endl; }
        // setters and getters
        // void set_month(int m) { // in-line definition (implicit)
        //     month = m;
        // }
        friend string print(DayOfTheYear doty);
        // friend DayOfTheYear operator+  (const DayOfTheYear& left_operand, const DayOfTheYear& right_operand);
        DayOfTheYear operator+  (const DayOfTheYear& left_operand);
        DayOfTheYear& set_month(int m) { // in-line definition (implicit)
            month = m;
            return *this;
        }
        int get_month() {
            return month;
        }
        // void set_day(int d);
        DayOfTheYear& set_day(int d);
        int get_day();
        void output() const{ cout<<month<<"/"<<day<<endl; }
};

string print(DayOfTheYear doty) {
    return to_string(doty.month) + " " + to_string(doty.day);
}

// friend version
// DayOfTheYear operator+  (const DayOfTheYear& left_operand, const DayOfTheYear& right_operand) {
//     DayOfTheYear temp;
//     temp.month = left_operand.month + right_operand.month;
//     temp.day = left_operand.day + right_operand.day;
//     return temp;
// }

// member version
DayOfTheYear DayOfTheYear::operator+  (const DayOfTheYear& left_operand) {
    DayOfTheYear temp;
    temp.month = month + left_operand.month;
    temp.day = day + left_operand.day;
    return temp;
}

inline DayOfTheYear& DayOfTheYear::set_day(int d) { // not in-line - if you organize code in separate files
    day = d;
    return *this;
}
inline int DayOfTheYear::get_day() {
    return day;
}

int main(void) {

    DayOfTheYear today, tomorrow(6, 8); // know as a object of a class (similar to instance of a class)
    // today.day = 7; // allowed if members are public
    // today.month = 6;
    // today.set_day(7);
    // today.set_month(6);
    today.set_day(7).set_month(6);

    cout<<print(today)<<endl;
    cout<<print(tomorrow)<<endl;

    today = today + tomorrow;
    cout<<print(today)<<endl;
    // dynamic memory allocation
    // DayOfTheYear *p_day = new DayOfTheYear();
    // DayOfTheYear *p_2day = new DayOfTheYear(8, 1);
    // p_day->output();
    // p_2day->output();

    // delete p_day;
    // delete p_2day;
    // cout<<"Bye"<<endl;
    // return 0;
}