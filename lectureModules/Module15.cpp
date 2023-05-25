#include <iostream>
#include <cstring>
using namespace std;

/*
- Array's name refers to the address of the 1st element of the array
- &arr means address of array of 5 elements. (has a notion of size of the array)
- void* is a valid type, you can type cast any pointer to void* and vice versa
- Some memory management routines often return pointers of void* type.
- Double pointer is a pointer to pointer to a double. **dptr
- Dynamic Memory Allocation is programmer's resposiblility
- Static memory allocation is compiler's resposiblility (when they fo out of scope).
- If you don't deallocate all allocated meory, you get memory leaks.
- C++11 came out with smart pointer 
*/

int main() {
    /*
    int arr[5] = {1, 2, 3, 4, 5};
    cout<<arr<<" "<< &arr[0]<<" "<<&arr<<endl;
    cout<<arr<<" "<<arr+1<<endl;
    cout<<&arr<<" "<<(&arr+1)<<endl;
    */
    /*
    char ch; // 1 character
    char* ch2; // 1 character pointer
    char ch3[4]; // 4 characters (array)
    char* ch4[4]; // 4 characters pointers (array)
    const char* ch5[4]; //4 constant char ptrs (array), they can't point anywhere else

    const char* suit[4] = {"Hello", "Hi", "Howdi", "Bye"};
    const char** dptr = suit;
    cout<<sizeof(suit)<<endl; // size of array (which is y char ptrs)
    */
    // The general style will be the following to access elements from 2d array or double ptr
    // const char* suit[4] = {"Hello", "Something", "Nothing", "Bye"};
    // const char** s = suit;
    /*
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++)
            cout<<*(*(s+i)+j)<<" ";
        cout<<endl;
    }
    */
    /*
    for(int i=0;i<4;i++) {
        const char* cptr = suit[i];
        while(*cptr != '\0') {
            cout<<*cptr<<" ";
            cptr++;
        }
        cout<<endl;
    }
    */
    

    return EXIT_SUCCESS;
}