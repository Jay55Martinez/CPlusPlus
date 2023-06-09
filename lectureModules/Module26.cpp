#include <iostream>
using namespace std;

/*
More examples overloading:

- Extraction (>>) and Insertion Operators (<<)
operator<<(basic_ostream<_CharT, Traits>& __out, char __c)
To print using:
the following you need to override insertion operator operator<< (insertion)
cout<<"Hello World"<<endl; // cascasing call
-------cout------T--<<endl;
To make cascading call happen, we will return the first arugment from the function
friend std::ostream& operator<< (std::ostream&, const DayOfTheYear& value)

- Pre and post increment and decrement
Unary ++ can be used in two ways pre or post increment
Both require writing a function: operator++
Pre-Increment:
friend version : need one argument
member version : need zero arguments
To implement post-increment operation, c++ complire calls the function with the extra int argument
Post-Increment:
friend version : need one argument + extra dummy int argument
member version : need zero arguments

Here is how it looks:
Friend version:
friend DayOfTheYear& operator++(DayOfTheYear one); // Pre
friend DayOfTheYear& operator++(DayOfTheYear one, int dummy_int_value); // post

Member version:
DayOfTheYear operator++(); // Pre
DayOfTheYear& operator++(int dummy_int_value); // post
*/
class DayOfTheYear {
    private:
        int month, day;
    public:
        DayOfTheYear() { cout<<"default constructor"<<endl; this->month = 0; this->day = 0; }
        DayOfTheYear(int m, int n) { cout<<"overloaded constructor"<<endl; (*this).month = m; (*this).day = n; }
        ~DayOfTheYear() { cout<<"deconstructor"<<endl; }
        friend string print(DayOfTheYear doty);
        // operator examples:
        friend std::ostream& operator<< (std::ostream& out, const DayOfTheYear& value);
        friend std::istream& operator>> (std::istream& in, DayOfTheYear& value);
        friend DayOfTheYear& operator++(DayOfTheYear& one);
        DayOfTheYear operator++(int dummy_int_value);
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

// friend function
string print(DayOfTheYear doty) {
    return to_string(doty.month) + " " + to_string(doty.day);
}

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

std::ostream& operator<< (std::ostream& out, const DayOfTheYear& value) {
    out<<value.month<<":"<<value.day<<endl;
    return out;
}
std::istream& operator>> (std::istream& in, DayOfTheYear& value) {
    in>>value.month>>value.day;
    return in;
}

// friend version
DayOfTheYear& operator++(DayOfTheYear& one) {
    one.month++;
    one.day++;
    return one;
}

// member version not define in-line
DayOfTheYear DayOfTheYear::operator++(int dummy_int_value) {
    DayOfTheYear temp = *this;
    this->day++;
    this->month++;
    return temp;
}

int main(void) {

    DayOfTheYear today, tomorrow(6, 8); // know as a object of a class (similar to instance of a class)
    today.set_day(7).set_month(6);
    cout<<"enter month and day values"<<endl;
    cin>>today;
    cout<<print(today)<<endl;
    cout<<print(tomorrow)<<endl;

    today = today + tomorrow;
    cout<<today;
    cout<<++today;
    today++;
    cout<<today;

    return 0;
}