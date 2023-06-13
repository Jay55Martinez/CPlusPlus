#include <iostream>
#include <vector>
using namespace std;
/*
19. Static members of a class belong to the class. They are shared between all objects.
Static members are created when the program starts and they remain alive till the end of the 
program. 
20. Static members need to be declared and initialize these initializations are done outside 
the body of the class.
21. What if there are more than 1 static member of a class. Is there a order in which they are
created? Answer NO. known as static initialization fiasco. Where compiler does not guarantee
any specific order of initialization for static members. They use "construct on first use"

Each class has a special pointer called vpointer that exists along with other members. 
This pointers points to a table vTable.
vTable: holds links to definitions of all of the funtions in the class.
They oftern are links to most specific implementation of the function, THis helps the compiler
know which function to call for dynamic binding
*/

class Base {
    public:
        Base() { cout<<"Base()"<<endl; }
        virtual ~Base() { cout<<"~Base()"<<endl; }
        virtual void funct() { cout<<"Base::funct()"<<endl; }
};

class Base2 {
    public:
        Base2() { cout<<"Base2()"<<endl; }
        virtual ~Base2() { cout<<"~Base2()"<<endl; }
        virtual void funct() { cout<<"Base2::funct()"<<endl; }
};

class Derived : public Base, public Base2 {
    public:
        Derived() { cout<<"Derived()"<<endl; }
        virtual ~Derived() { cout<<"~Derived()"<<endl; }
        virtual void funct() { cout<<"Derived::funct()"<<endl; }
};

int main(void) {
    cout<<"Hello"<<endl;
    // Base *p1 = new Base();
    // cout<<endl;

    // Base *p2 = new Derived();
    // cout<<endl;

    // p1->funct();
    // p2->funct();
    // cout<<endl;

    // delete p1;
    // delete p2;
    // cout<<"Bye"<<endl;

    vector<Base*> many_ptrs = {new Base(), new Base(), new Derived(), new Derived(), new Base(), new Derived()};
    for(auto one_ptr : many_ptrs) 
        one_ptr->funct();
    for(auto one_ptr : many_ptrs) 
        delete one_ptr;
    return 0;
}