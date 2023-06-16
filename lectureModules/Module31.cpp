#include <iostream>
#include <vector>
using namespace std;
/*
- Sneakpeak at the compiler.
class X {};
Compiler automatically generates a few functions for your class X.
3 from C++98 include:
- default constructor: X one;
- copy constructor: X two(one);
- copy assignment operator: X two = one;
- destructor ~X
2 from C++11 include:
- move constructor
- move assignment operator
In other words:
class X {};
is equivalent to
class Y {
public:
Y () = default;
Y (Y const& other) = default;
Y& operator= (Y const& other) = default;
Y (Y && other) = default;
Y& operator= (Y && other) = default;
~Y() = default;
};
//use =delete to ask the compiler NOT to define some of these functions.
Rule of 0:
C++ core guidelines state: "If you can avoid defining default operations,
DO!".
Reason is cleanest semantics. In other words, ket compiler do the work.
Before we start, we have to know a few things:
- If you write any of these, compiler TRIES to write the others:
--Copy constructor
--Copy Assignment operator
--destructor
- If you write any of these, compiler DOES NOT GUARANTEE the default
constructor:
--Copy constructor
--overloaded constructor
--move constructor
- If you write any of these, compiler DOES NOT GUARANTEE the move
functions:
--Copy constructor
--Copy Assignment operator
--destructor
- If you write any of these, compiler DOES NOT write any of the other 5
(it
enforces rule of 5):
--move constructor
--move Assignment operator
default copy constructor uses shallow-copy
One of the biggest challenges in C++ (before C++11) was the problem with
temporaries. c=a+b operation requires compiler to save the answer in a
temporary
variable before assigning it to the variable on left.
&& is a reference to those temporaries (r-value reference)
Modern compilers automatically use move semantics for return values
(C++17)
known as return value optimization. STL also uses move semantics
automatically
starting in C++11.
RAII encourages to allocate/acqurie resources in constructor and
deallocate/release them in destructor. It encourages use of stack
allocated
variables.
*/
class DynamicArray {
    private:
        size_t m_size;
        int *m_arr;
        public:
        explicit DynamicArray(size_t size) {
            cout << "overloaded constructor" << endl;
            m_size = size;
            m_arr = new int[m_size]{0};
        }
        DynamicArray(const DynamicArray &o) {
            cout << "copy constructor" << endl;
            m_size = o.m_size;
            m_arr = new int[m_size];
            for (size_t ii = 0; ii < m_size; ++ii)
                m_arr[ii] = o.m_arr[ii];
        }
        DynamicArray &operator=(const DynamicArray &o) {
            cout << "assignment operator" << endl;
            if (&o != this) { // to avoid self-copy
                delete[] m_arr;
                m_size = o.m_size;
                m_arr = new int[m_size];
                for (size_t ii = 0; ii < m_size; ++ii)
                m_arr[ii] = o.m_arr[ii];
            }
            return *this;
        }
        /*
        //Alternative implemntation uses "copy and swap idiom"
        DynamicArray& operator= (const DynamicArray &o){
        cout<<"assignment operator again"<<endl;
        swap(m_arr, o.m_arr);
        swap(m_size,o.m_size);
        return *this;
        }
        */
        // DynamicArray(const DynamicArray&& o) = delete;
        // DynamicArray& operator= (DynamicArray &&o) = delete;
        DynamicArray(DynamicArray &&o) {
            cout << "move constructor" << endl;
            m_size = o.m_size;
            m_arr = o.m_arr;
            o.m_size = 0;
            o.m_arr = nullptr;
        }
        DynamicArray &operator=(DynamicArray &&o) {
            cout << "move assignment operator" << endl;
            if (&o != this) { // to avoid self-copy
                delete[] m_arr;
                m_size = o.m_size;
                m_arr = o.m_arr;
                o.m_size = 0;
                o.m_arr = nullptr;
            }
            return *this;
        }
        ~DynamicArray() { delete[] m_arr; }
        size_t get_size() const { return m_size; }
    };

int main(void) {
    cout << "Start" << endl;
    DynamicArray d1(100);
    cout << d1.get_size() << endl;
    // DynamicArray d2(d1); //uses copy constructor
    // DynamicArray d2 = d1; //uses copy constructor
    // DynamicArray d3(100); d3 = d1; //uses assignment operator
    DynamicArray d4(move(d1)); // move constructor
    cout << d1.get_size() << endl;
    cout << d4.get_size() << endl;
    d1 = move(d4); // move assignment operator
    cout << d1.get_size() << endl;
    cout << d4.get_size() << endl;
    cout << "Bye" << endl;
    return EXIT_SUCCESS;
}
