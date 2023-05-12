#include <iostream>
#include <limits>
using namespace std;

/*
-In C++, we often use different operators with data types
4*5+3= 20+3 = 23
-When using operators with mix and match, you should be very careful
-Every character symbol has a corresponding ASCII code.
-C++ has 3 ways of initializing a variable =, (), {}
-C++ also has another version of string -> borrowed from C -> C-String which is essentially a
special character array (ends with a null character)
-string vs CString : cstring is faster than string type
-cin for string does not accept a space or "enter" inside the string
-getline is able to accept spaces but does not promt the user for a input.r
-be careful using operators : they have precedence
-most common mistake is the use of = rather than ==
-In C++ conditional operators use 0 and nonzero values which may not be binary
*/
int main()
{

    // char my_c; 
    // cin>>my_c;
    // cout<<my_c + 10<<endl;

    // char my_char = 'A'+10;
    // cout<<(int)my_char<<endl;
    // int my_int = 'A'+10;
    // cout<<my_int<<endl;

    // string str1 = "hello"; 
    // string str2 ("hi");
    // string str3 {"howdi"};
    // cout<<str1<<", "<<str2<<", "<<str3<<endl;

    // char cstring1[] = "Hello World!";
    // char *cstring2 = (char*)"Hello World!!";
    // cout<<cstring1<<" "<<cstring2<<endl;

    // string str1, str2;
    // cin>>str1;
    // cin.ignore(10, '\n');
    // getline(cin, str2);
    // cout<<str1<<", "<<str2<<endl;
/*
    int ii = 0;
    cin>>ii;
    // if(ii>10){
    //     cout<<"Big"<<endl;
    // } else { 
    //     cout<<"Small or Equal"<<endl;
    // }

    //ternary operator ?:
    //condition ? true_statement : false_statement
    (ii>10) ? cout<<"Big"<<endl : cout<<"Small or Equal"<<endl;
*/
    // int i = 100;
    // i += 50;
    // cout<<i<<endl;
    // cout<<i++<<", "<<++i<<endl; //post and pre

    // if (i>150) {
    //     cout<<"greater";
    //     cout<<endl;
    // }
    // else if (i<150) {
    //     cout<<"smaller";
    //     cout<<endl;
    // }

    // if (i==150) {
    //     cout<<"equal"<<endl;
    // }
    // else {
    //     cout<<"not greater not smaller"<<endl;
    // }

    // for (int i = 10; i>0; i--) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // int i=10; //initial 1.
    // while(i>0) { //condition 2, 4
    //     cout<<i <<" "; //3, 5
    //     i--; //update
    // }
    // cout<<endl;
    // i=10;
    // do {
    //     cout<<i <<" ";
    //     i--;
    // } while(i>0);
    // cout<<endl;

    // int i = 10;
    // while (i > 0) {
    //     if (i==5){
    //         break;
    //     } else {
    //         cout<<i <<" ";
    //     }
    //     i--;
    // }
    // cout<<endl;

    // i = 10;
    // while (i > 0) {
    //     if (i==5){
    //         i--;
    //         continue;
    //     } else {
    //         cout<<i <<" ";
    //     }
    //     i--;
    // }
    // cout<<endl;

    string str ("Test string");
    for (unsigned i=0; i<str.length(); ++i)
        cout << str.at(i)<< " ";
    cout<<endl;
    for (unsigned i=0; i<str.length(); ++i)
        cout << str[i]<< " ";
    cout<<endl;
    for(char oneChar :str)
        cout << oneChar << " ";
    cout<<endl;

    string my_string = "k.";
    cout<<my_string.find('k')<<endl;

    return EXIT_SUCCESS;
}