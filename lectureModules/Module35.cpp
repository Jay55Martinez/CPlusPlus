// STOPPED AT 24:40 IN VIDEO LECTURE
#include <iostream>
#include <vector>
using namespace std;




void print_me(string&& name) { cout<<"Lvalue: "<<name<<endl; }
void print_me(string& name) { cout<<"Rvalue: "<<name<<endl; }
int set_value() { return 6; }
int globalVar = 10;
int& set_global() { return globalVar; }


int main(void) {

    string fname = "John";
    string lname = "Bill";
    string fullname = fname + lname;
    print_me(fname);
    print_me(fullname);
    print_me(fname + lname);

    int x = 660; // ok, x is lvalue, 660 is rvalue
    int *y = &x; // ok, y is lvalue, &x is result of operator rvalue
    // int z; 660 = z; // not ok, 660 is literal which is rvalue, can't be on LHS of expression
    // int *yy = &660; // not ok, 660 is rvalue (which is in a temp), can't use & (lvalue ref) for rvalue
    // set_value() = 3; // rvalue on LHS, not allowed
    int xx = set_value();
    cout<<to_string(xx)<<endl;
    set_global() = 500; // set_global() is lvalue
    cout<<globalVar<<endl; 

    int xy = 10; int& xyref = xy; xyref++; 
    // int& yref = 10; // not ok, 10 is a literal, stored by comiler in a temp. you can't store temp variable in ref
    // TO FIX: use key
    const int& yref = 10;
    // internally, complire did this:
    // int _internal_hidden_var = 10; const int& yref = _internal_hidden_var;
    int a = set_value(); // ok
    // int& aa = set_value(); // not ok
    const int& aa = set_value(); // ok
    int&& aa2 = set_value(); // ok

    return 0;
}

/*
Lvalue and Rvalue references & Move semantics
Compiler internally creates temporary copies for each variable/function call throughout the 
execution of this program. This is also true for return values of our functions all of these
copies are stored in temporary variables that are later discarded by the compiler.
Remember: & is lvalue reference and && is rvalue reference\
KEY to FIX THIS: Use rvalues or use const

In C/C++ each expression is divided into Left-Hand-Side and Right-Hand-Side
In earlier days of C/C++ things were easy where lvalues were on LHS and r values
were on RHS
Example:
int c = 3 + 4; c is lvalue and 3 + 4 is rvalue
This primitive understanding is no longer entirely true (not always true). lvalues 
can sometimes be on RHS. C++ compilers have specifically chosen to not allow rvalues on
LHS

int y = a; aa is lvalue. lvalue can be on RHS which is allowed. expression is valid
int y = f(x); // x is lvalue, f(x) is rvalue, y is lvalue
int *y = &x; // x is lvalue, &x is rvalue
func_g(new myClass()); // MyClass anoyobject is rvalue.
MyClass s = func(s); // s is lvalue, m is lvalue, func(m) is rvalue

Value categories in C++
        expression
        /        \
    glvalue     rvalue
    /     \     /     \
lvalue   xvalue      prvalue

xvalue are expiring values: they have temporary identites (ie.. if they are vased on rvalue references)
glvalue are generalized lvalues: expression that refer to objects with identity
prvalue are pure rvalues: expression without identity
lvalue are all glvalues: that are not expiring values
rvalues are both xvalues and prvalues

let's simplify this:
lvalues point to a specific memory address 
rvalues do not have specific memory address.
- since lvalues are objects with specific memory location (assigned), this means that compiler cannot
use that assigned memory location for some other variable.
- on the other hand, rvalues are stored in temporrary memory locations (ie.. you can't use & on them but you can use &&)
and the may be re-assigned to other variables by compiler if needed.
=> lvalue refs are &, and rvalue refs are &&
&& gives tou access to the memory locations used by those temporaries

Examples of lvalues:
-named variable, array subscript ref, derefenced ptr, function call that returns a reference
Examples of rvalues:
-literals, results fo operators, function call that does not return a reference
Examples:


*/