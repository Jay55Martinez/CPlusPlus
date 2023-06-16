#include <iostream>
#include <memory>

using namespace std;

/*
RAII: 
Smart Ponters is an example of RAII where the responceablity of the clean is the complire
not the programmer. Good at avoiding memory leaks
If your program throws an error you destructor my not be called if you are using raw pointers.
Use smart pointers instead : unique_ptr, shared_ptr, weak_ptr
make_shared() - c++11
make_unique which is avalible c++14 onwards
Khoury is c++11
Unique pointers can not be copied and they point to one memory location
Shared pointers my be shared. Internally, the compiler uses reference tracking which keeps track of
how many pointers are pointing to a memory allocation when you have 0 pointers pointing to a memory
allocation then the compiler deletes that memory allocation
Since compiler does reference counting for you shared pointer are computationally heavier than unique pointers
Weaks pointers are kind of shared pointers but they don't affect reference count.
They can tell you if memory still exists or has been deleted.
You can convert weak pointer into shared pointer by locking it (lock()) be careful when using them together

*/

class Test {
    public:
        Test(int id) : m_id(id) { cout<<"+"<<m_id<<endl; }
        ~Test() { cout<<"-"<<m_id<<endl; }
        int get_id() const { return m_id; }
    private:
        int m_id;
};

struct TreeNode {
    TreeNode(int id) : item(id) {}
    Test item;
    // shared_ptr<TreeNode> parent; // causes cycles
    weak_ptr<TreeNode> parent;
    shared_ptr<TreeNode> left_child;
    shared_ptr<TreeNode> right_child;
};

void do_something(Test* t);

void use_pointers() { 

    auto r = make_shared<TreeNode>(1);
    auto lc = make_shared<TreeNode>(2);
    auto rc = make_shared<TreeNode>(3);
    r->left_child = lc;
    r->right_child = rc;
    lc->parent = r;
    rc->parent = r;
    // be careful writing cycles in your programs

    /*
    shared_ptr<Test> p1 = make_shared<Test>(1);
    cout<<"Count: "<<p1.use_count()<<endl;
    weak_ptr<Test> w1 = p1;
    cout<<"Count: "<<p1.use_count()<<endl;
    cout<<"ID: "<<p1->get_id()<<endl;
    cout<<w1.expired()<<endl;
    // cout<<"ID: "<<w1.getid()<<endl; // not allowed
    shared_ptr<Test> p2 = w1.lock();
    cout<<"Count: "<<p2.use_count()<<endl;

    p1.reset();
    cout<<"Count: "<<p2.use_count()<<endl;
    cout<<w1.expired()<<endl;
    p2 = nullptr;
    cout<<"Count: "<<p2.use_count()<<endl;
    cout<<w1.expired()<<endl;
    */

    /*
    shared_ptr<Test> p1 = make_shared<Test>(1);
    cout<<"Count: "<<p1.use_count()<<endl;
    shared_ptr<Test> p2 = p1;
    cout<<"Count: "<<p2.use_count()<<endl;
    */

    // always dynamicaly allocate block of memory derectly in the name of the pointer
    /*
    Test* t = new Test(1);
    unique_ptr<Test> a(t);
    delete t;
    */

    /*
    unique_ptr<Test> a(new Test(1));
    unique_ptr<Test[]> b(new Test[2]{2, 3});
    cout<<"ID: "<<a->get_id()<<endl;
    cout<<"ID: "<<b[0].get_id()<<endl; // array specialization is not allowed
    cout<<a.get()<<endl;
    unique_ptr<Test> c = move(a);
    cout<<a.get()<<endl;
    do_something(a.get());
    */

    // version 1 uses raw pointers causes memory leak if exception
    /*
    Test* a = new Test(1);
    Test* b = new Test[2]{2, 3};

    do_something(a);

    delete[] b;
    delete a;
    */
}

int main() {
    cout<<"Start"<<endl;
    try {
        use_pointers();
    } catch(const exception &e) {
        cout<<"exception caugth"<<endl;
    }
    cout<<"End"<<endl;
    return 0;
}

void do_something(Test* t) {
    throw exception();
}