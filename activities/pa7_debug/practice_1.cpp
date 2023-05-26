
// Program to check if the user-provided number is a palindrome
// Number of errors/bugs = 25
/*
List of bugs:
funtion not working
return types wrong
variable types wrong
operations wrong
*/
//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.
#include<iostream>
using namespace std;

bool func(int n); 

int main() { // return type int
        int input = 1001;

        if (func(input)) { 
        cout<<"It is not a palindrome"<<endl;
        }
        else {
        cout<<"It is a palindrome"<<endl;
        }
		
        return 0;
}

//the return value of your func should be true / false only
bool func(int n) // fix return type
{
        int given_number = n;
        int temp = 0; 
        int orginal = n; // store unchanged n value

        while (n != 0) {
                int remainder = n%10; // remianeder
                n /= 10; 
                temp = temp * 10 + remainder;         
        }

        if (orginal == temp)  
        {
                return false;
        }
        else
        {
                return true;
        }
}

