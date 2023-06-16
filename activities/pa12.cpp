#include <iostream>
#include <cstring>
using namespace std;

class MyString { 
  char* str;
  public:
    MyString() : str{nullptr} { // Default Constructor
      str = new char[1];
      str[0] = '\0';
    };             
    MyString(char* val) {    // Constructor with 1 arguments
      if (val == nullptr) {
        str = new char[1];
        str[0] = '\0';
      }
      else {
        str = new char[strlen(val) + 1];
        strcpy(str, val);
        str[strlen(val)] = '\0';
        cout << "The given string is: "
             << str << endl;
      }
    }
    MyString(const MyString& source) {  // Copy Constructor
      str = new char[strlen(source.str) + 1];
      strcpy(str, source.str);
      str[strlen(source.str)] = '\0';
    }
    MyString(MyString&& source) { // Move Constructor
      str = source.str;
      source.str = nullptr;  
    }
    ~MyString() { delete str; }  // Destructor
};

int main(void) {
  cout << "Start!" << endl;
  
  MyString a;
  MyString b{ (char*)"Hello" };
  MyString c{ a };
  MyString d{ MyString{ (char*)"World" } };
 
  cout << "Bye" << endl;
}