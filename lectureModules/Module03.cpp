// This is my lecture demo (Adeel Bhutta - 5/4)
/*
This module goes over variables and how they are stored in memory
*/
#include <iostream>
#include <limits>
using namespace std;
int main() {

  int ii; char cc; short ss; float ff; double dd; string str; bool bb;
  cout<<"size of int:"<<sizeof(ii)<<"\n"
      <<"size of char:"<<sizeof(cc)<<"\n"
      <<"size of short:"<<sizeof(ss)<<"\n"
      <<"size of string:"<<sizeof(str)<<"\n"
      <<"size of bool:"<<sizeof(bb)<<"\n"
      <<"size of float:"<< sizeof(ff)<<"\n"
      <<"size of double:"<< sizeof(dd)<<endl;
  cout<<"memory address of int:"<<&ii<<"\n"
      <<"memory address of short:"<<&ss<<"\n"
      <<"memory address of float:"<< &ff<<"\n"
      <<"memory address of double:"<< &dd<<endl;
  cout<<"value of int:"<<(ii)<<"\n"
      <<"value of char:"<<(cc)<<"\n"
      <<"value of short:"<<(ss)<<"\n"
      <<"value of string:"<<(str)<<"\n"
      <<"value of bool:"<<(bb)<<"\n"
      <<"value of float:"<< (ff)<<"\n"
      <<"value of double:"<< (dd)<<endl;

  cout<<"Min value of int:"<<numeric_limits<int>::min() <<'\n';
  cout<<"Max value of int:"<<numeric_limits<int>::max() <<'\n';

  int i = -1;
  cout<<"signed int:"<<i<<endl;
  unsigned int ui = -1;
  cout<<"unsigned int:"<<ui<<endl;
  cout<<"signed int:"<<hex<<i<<endl;
  cout<<"unsigned int:"<<hex<<ui<<endl;

  return EXIT_SUCCESS;
}

/*
-Be careful with the size of variables because that affects the range of values you can store in that variab;e
-Default is "Signed" rep for variable. "unsigned" -> 2s complement notation (signed)

-2s complement - negative numbers.
approach: 
+ve number, 2s complement number is same as it self, 
-ve number: take 2s complement for it
process: start with +ve number then take 1s complement and then add 1 to it.

Q: find 2s complement rep for -3 using 3 bits
-3 : 011 -> 100 -> 101
remember: MSB (most significant bit, left-most bit) => 1 (negative), 0 (positive)
Q: what is 011? MSB is 0 so its positive +3
Q what is 101? MSB is 1 hence it is negative. use "reverse process"
101 -> 010 -> 011 => +3 
which means 101 was 2s complement repr of +3 i.e., it is actually -3.

//3-bit number (unsigned, signed)
000 = 0 => +0
001 = 1 => +1
010 = 2 => +2
011 = 3 => +3
100 = 4 => -4
101 = 5 => -3
110 = 6 => -2
111 = 7 => -1
//Biggest unsigned number is smaller signed negative number
//IndexOutofBoundException (IOOBE). 

fffffffff = 11111111111....111111
*/
