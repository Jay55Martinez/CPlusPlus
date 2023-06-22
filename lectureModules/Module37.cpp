#include <iostream>
#include <thread>
using namespace std;

/*
So far we have used a single main thread in most of our programs but C++
offers a lot of support for parallel programming. This allows you to use multiple cores
you may have available.

Prior to C++11, we would use extenal libraries (boost). Now we have built in support for
multiple threads: <thread>, <this-thread>, <future>, <mutex>

running these funcitons in different threads
*/

int value = 0;
void foo() { cout<<hex<<"foo() "<<this_thread::get_id()<<endl; value = 10; }
void bar() { cout<<hex<<"bar() "<<this_thread::get_id()<<endl; value = 11; }
int main() {

    // This is our main thread
    cout<<"value: "<<value<<endl;
    // Create two threads, which run our given fucntion
    thread first(foo);
    thread second(bar);
    /*
    HERE, we have 3 threads running. If you have multiple processors, the would probably 
    run on independent cores. IF oyou run multiple threads on a single core, it will be slower
    than running one thread
    */
    cout<<hex<<"main::runing three threads in parallel"<<this_thread::get_id()<<endl;
    cout<<"value:"<<value<<endl;
    first.join();
    cout<<"value:"<<value<<endl;
    second.join();
    cout<<"value:"<<value<<endl;
    cout<<"back to only main thread "<<this_thread::get_id()<<endl;

    return 0;
}