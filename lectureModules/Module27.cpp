#include <iostream>
#include <vector>
using namespace std;
/*
Two important relationship: composition and inheritance
- composition is about an object being a member of another class
(aggregation). Known as HAS-A relationship
- inheritance is "IS-A" relationship.
- Look for commonality
- Parent-Child, Base-Derived, Super-Sub
- Holiday class is a child/derived/sub class of a Parent/Super/Base class
called DayOfYear
- Child classes have two types: Child type and parent type. In C++ lingo,
we say that a child class has two parts (a child part and the parent
part. Parent part is inherited but the child part is the extension)
- when you create a object of the child class, C++ compiler uses the
parent constructor as well (it created the parent part and then the
child part) - this idea is called constructor chaining
- C++ also have multiple inheritances, not in java e.g., class Holiday :
public DayOfYear, public SomeoTherClass
- in Java you have keyword "interface", not in C++. Here interface word
means API -> public functions of a class.
- What does child class inherit from parent class: it inherits all public
and protected members excluding the constructors and destructor.
- If you define a function of a parent class inside a child class, then
it is called REDEFINITION, not polymorphism. Polymorphism in C++
requires keyword "virtual".
*/
//struct DayOfYear {
class DayOfYear {
    protected:
        int month, day;
    public:
        DayOfYear() : DayOfYear(-1,-1) { cout<<"default constructor"<<endl; } //delegation
        DayOfYear(int m, int d) { cout<<"overloaded constructor"<<endl; month=m; day=d; }
        ~DayOfYear() { cout<<"destructor"<<endl;}
        //void set_month(int in) { month=in; } //in-line definition (implicit)
        DayOfYear& set_month(int in) { month=in; return *this;} //in-line
        // definition (implicit)
        int get_month() { return month; }
        //void set_day(int in);
        DayOfYear& set_day(int in);
        int get_day();
        void output() const;// { cout<<month<<"/"<<day<<endl; }
        DayOfYear operator+ (const DayOfYear& one_operand); //binary
        DayOfYear operator- (); //unary
        friend string print(DayOfYear d);
        //friend DayOfYear operator+ (const DayOfYear& left_operand, const
        friend DayOfYear operator+ (const DayOfYear& left_operand, const int& right_operand); //binary
        friend std::ostream& operator<< (std::ostream&, const DayOfYear& value);
        friend std::istream& operator>> (std::istream&, DayOfYear& value);
        friend DayOfYear operator++(DayOfYear& d); //friend version for pre-
        DayOfYear operator++(int dummy); //member version for post-increment,
};

//inline void DayOfYear::set_day(int in) {day=in;}
inline DayOfYear& DayOfYear::set_day(int in) {day=in; return *this;}
inline int DayOfYear::get_day() {return day;}
void DayOfYear::output() const { cout<<month<<"/"<<day<<endl; }
string print(DayOfYear d) {
return to_string(d.month) + "-" +to_string(d.day);
}

/*
//Friend Version
DayOfYear operator+ (const DayOfYear& left_operand, const DayOfYear&
right_operand){
DayOfYear temp;
temp.month = left_operand.month + right_operand.month;
temp.day = left_operand.day + right_operand.day;
return temp;
}*/

//Friend Version
DayOfYear operator+ (const DayOfYear& left_operand, const int& right_operand){
    DayOfYear temp;
    temp.month = left_operand.month + right_operand;
    temp.day = left_operand.day + right_operand;
    return temp;
}

//Member Version
DayOfYear DayOfYear::operator+ (const DayOfYear& one_operand){
    DayOfYear temp;
    temp.month = month + one_operand.month;
    temp.day = day + one_operand.day;
    return temp;
}
//Member Version
DayOfYear DayOfYear::operator- (){
    DayOfYear temp;
    temp.month = -1*month;
    temp.day = -1*day;
    return temp;
}
std::ostream& operator<< (std::ostream& out, const DayOfYear& value) {
    out << value.month << ":" << value.day << endl;
    return out;
}
std::istream& operator>> (std::istream& in, DayOfYear& value) {
    in >> value.month >> value.day;
    return in;
}
//friend version
DayOfYear operator++(DayOfYear& d){
    d.day++;
    d.month++;
    return d;
}
//member version not defined in-line
DayOfYear DayOfYear::operator++(int dummy){
    DayOfYear temp = *this;
    this->day++;
    this->month++;
    return temp;
}

//Composition
class Calendar{
    public:
        int year;
        vector<DayOfYear> days;
        Calendar() { cout<<"Calendar()"<<endl;}
        Calendar(int yr, vector<DayOfYear> ds) { year = yr; days = ds; cout<<"Calendar(int,vector)"<<endl; }
};

//Inheritance
class Holiday : public DayOfYear {
    public:
        Holiday() {cout<<"default constructor - holiday"<<endl;}
        void output() const { cout<<"H:"<<month<<"/"<<day<<endl; }
/*void output() {
cout<<"H:"<<get_month()<<"/"<<get_day()<<endl;
}*/
};

int main(void) {
    /*
    DayOfYear aDay(6,1);
    aDay.output();
    vector<DayOfYear> ds(1);
    Calendar mine(2023, ds);
    cout<<mine.year<<"="<<mine.days[0]<<endl;
    */
    Holiday hd;
    hd.output();
    //cout<<mine<<endl;
    /*
    DayOfYear today, tomorrow(6,2);
    //today.set_month(6).set_day(1);
    cout<<"Enter month and day values:";
    cin>>today;
    today.output(); tomorrow.output();
    DayOfYear aday = today + tomorrow + 1;
    cout<<print(aday)<<endl;
    DayOfYear anotherday = -aday;
    cout<<print(anotherday)<<endl;
    cout<<anotherday++;
    cout<<++anotherday;
    */
    cout<<"Bye"<<endl;
    return EXIT_SUCCESS;
}