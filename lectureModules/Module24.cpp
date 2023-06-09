// STOPPED AT 32:29
#include <iostream>
using namespace std;

/*
struct DayOfTheYear {
    int month, day;
    void output() const{ cout<<month<<"/"<<day<<endl; }
};
*/

/*
  const qualified functions are not allowed to modify members of the struct/class
  Members of a structure are public by default which means they accessable outside the 
  the scope of the struct
  By default: members of a class are private
  Best practice: define all member of your class as private. Provide public functions that allow access to
  private members inderectly. Writing these functions is called "designing the interface for the class"
  these are know as your getters and setters this idea is know as emcapuslation
  - Caution the word "interface" does not exist.
  - Programmers must initialize members of the class
  - Functions can be defines inside the body of the class: called in-line
  Or outside the class: not in-line - if you organize code in separate files
  - inline keyword asks the compiler (explicitly) to decide if defining inline will be more efficient. If it is you are
  asking the compiler to do that.
  - You can allocate memory for the objects dynamicly (at run time) using pointers and keyword new. If you don't use new
  i.e. allocate memory then your point might be a dangling pointer
  Guideline for your getters and setters: Getters should be getters and they should not be setters same for setters
  This idea is know as "Single Responsiblity Principle"
  - By default the complire writes the default constructor for the class (along with a few other funcitions)
  - constructors are public fuctions with the same name as the name of the class. They can be overloaded.
  They are called by the compiler when you create an object
  - When you overload the constructor the complire no longer uses default
  - Constructors are public functions. You may also define private constructors in c++ that means they are
  only available for members inside the class (other constructors or friend functions). They may be useful in
  in some situations. "named parameter idiom" C++
  - in c++ this is a pointer. use -> to access members 
  - To make cascading function calls return reference of class/type from function
*/
class DayOfTheYear {
    private:
        int month, day;
    public:
        DayOfTheYear() { cout<<"default constructor"<<endl; this->month = 0; this->day = 0; }
        DayOfTheYear(int m, int n) { cout<<"overloaded constructor"<<endl; (*this).month = m; (*this).day = n; }
        // setters and getters
        // void set_month(int m) { // in-line definition (implicit)
        //     month = m;
        // }
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
    today.output();
    tomorrow.output();

    // dynamic memory allocation
    DayOfTheYear *p_day = new DayOfTheYear();
    DayOfTheYear *p_2day = new DayOfTheYear(8, 1);
    p_day->output();
    p_2day->output();
    cout<<endl;
    return 0;
}