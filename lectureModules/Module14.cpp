#include <iostream>
#include <cstring>
using namespace std;
/*
Pointers: 
Address of pointer:
every address has the same address size
--> &ptr
Declaring - 
int* ptr = 0;
int * ptr = 0;
int *ptr = 0;
int*ptr = 0;
// must have a valid a address else it is a dangling pointer
derefrenecing: is getting the value of variable that your pointer is pointing to
--> *ptr
// Principle of least Privilages - const
1. const pointer, const data (using dereferencing)
2. const pointer, non-const data
3. non-const pointer, const data (using dereferencing)
4. non-const pointer, non-const data (using dereferencing)
*/

// IN C++ everything is pass by value ... if you pass by reference, you are passing the value
// of reference. If you pass by pointer, pointer also gets the value
// void myFunction(int var); // Pass by Value
void myFunction(int &var); // Pass by Reference
void myFunction(int* var); // Pass by Pointer

void myFunction(int* var_ptr) { // use const to restrict
    *var_ptr = *var_ptr + 1;
}

void myFunction(int &var_ref) { //pass by ref, var_ref is an alias of a
    var_ref++; // equivalent to doing a++
}

// void myFunction(int var) {
//     var = var+1;
// }

int main() {
    /*
    int a = 10;
    cout<<a<<endl;
    myFunction(&a);
    myFunction(a);
    cout<<a<<endl;
    */
    /*
    int var = 9;
    cout<<"Value: "<<var<<endl;
    cout<<"address: "<<&var<<endl;
    cout<<"Size: "<<sizeof(var);
    int* ptr = &var;
    cout<<"Value from: "<<*ptr<<endl;
    cout<<"Value in: "<<ptr<<endl;
    cout<<"address: "<<&ptr<<endl;
    cout<<"size: "<<sizeof(ptr)<<endl;
    cout<<endl;
    double dvar = 11.3;
    cout<<"Value: "<<dvar<<endl;
    cout<<"address: "<<&dvar<<endl;
    cout<<"Size: "<<sizeof(dvar);
    double* dptr = &dvar;
    cout<<"Value from: "<<*dptr<<endl;
    cout<<"Value in: "<<dptr<<endl;
    cout<<"address: "<<&dptr<<endl;
    cout<<"size: "<<sizeof(dptr)<<endl;
    */
    /*
    int arr[5] = {1, 2, 3, 4, 5};
    //cout<<arr<<" "<<&arr[0]<<" "<<&arr<<endl;
    int* ptr_arr = arr;

    for (int i=0; i<5; i++){
        cout<<"V: "<<arr[i]<<" A: "<<&arr[i]<<endl;
    }
    cout<<endl; // ^^^^^ prints the same values and addresses
    for (int i=0; i<5; i++){
        cout<<"V: "<<*(ptr_arr+i)<<" A: "<<ptr_arr+i<<endl;
    }
    cout<<endl; // ^^^^^ prints the same values and addresses
    for (int i=0; i<5; i++){
        cout<<"V: "<<ptr_arr[i]<<" A: "<<&ptr_arr[i]<<endl;
    }
    cout<<endl; // ^^^^^ prints the same values and addresses
    for (int i=0; i<5; i++){
        cout<<"V: "<<*(arr+i)<<" A: "<<arr+i<<endl;
    }
    */
// arr and ptr_arr are equivalent. arr is const ptr.
    /*
    char greeting[] = "Hello World!!!";
    // const char* ptr_c = "Hello World 456!" + 4;
    const char* ptr_c = "Hello World!!!";
    cout<<ptr_c<<endl;
    */
    /*
    char cstr[15] = "Hello World!!!";
    char* pp = cstr;
    while(*pp) {
        cout<<*pp<<" ";
        pp++;
    }
    cout<<endl;
    char* pp1 = cstr+strlen(cstr)-1;
    while(*pp1) {
        cout<<*pp1<<" ";
        pp1--;
    }
    */
    /* 1
    int var = 10, var1 = 20;
    const int* const ptr = &var;
    // *ptr=100; // not ok
    ptr=&var; // not ok
    var = 100; // ok
    */
    /* 2
    int var = 10, var1 = 20;
    int* const ptr = &var;
    *ptr = 100; // ok
    ptr = &var; // not ok
    var = 100; //ok
    */
    /* 3
    int var = 10, var1 = 20;
    const int* ptr = &var;
    *ptr = 100; // not ok
    ptr = &var; // ok
    var = 100; // ok
    */
    /* 4
    int var = 10, var1 = 20;
    int* ptr = &var;
    *ptr = 100;
    ptr = &var;
    var = 100;
    */

    int myArray[5] = {};
    int* pTemp[5] = {myArray, myArray+1, myArray+2, myArray+3, myArray};
    //assume myArray starts at address 0xf0e0 and each integer uses 4 bytes.
    cout<<*pTemp+4<<endl;
    cout<<&myArray[4];
    
    return EXIT_SUCCESS;
}