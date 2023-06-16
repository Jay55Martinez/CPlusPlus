#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class MyString {
  unique_ptr<char[]> str;

public:
  MyString() : str(nullptr) { // Default Constructor
    str.reset(new char[1]);
    str[0] = '\0';
  }

  MyString(const char* val) { // Constructor with 1 argument
    if (val == nullptr) {
      str.reset(new char[1]);
      str[0] = '\0';
    } else {
      size_t length = strlen(val);
      str.reset(new char[length + 1]);
      strcpy(str.get(), val);
      str[length] = '\0';
      cout<<"The given string is: "<<str.get()<<std::endl;
    }
  }

  MyString(const MyString& source) { // Copy Constructor
    size_t length = strlen(source.str.get());
    str.reset(new char[length + 1]);
    strcpy(str.get(), source.str.get());
  }

  MyString(MyString&& source) noexcept : str(nullptr) { // Move Constructor
    str = std::move(source.str);
  }

  ~MyString() = default; // Destructor not needed because of smart pointers
};

int main() {
  cout<<"Start!"<<endl;

  MyString a;
  MyString b("Hello");
  MyString c(a);
  MyString d(MyString("World"));

  cout<<"Bye"<<endl;
}
