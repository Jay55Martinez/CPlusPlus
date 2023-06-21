// Jay Martinez -- Assignment 6 -- 6/19/23
/*
Class Address:

Constructor:
default

Fields:
street : string
state : char*
city : string
street_num : string
zip : string

Functions:
set_street() : void
set_state() : void
set_city() : void
set_street_num() : void
set_zip() : void
is_valid : bool - returns true if the address is valid false if it is not
*/
#include <string> 
using namespace std;

class Address{
    public:
        void set_street();
        void set_state();
        void set_city();
        void set_street_num();
        void set_zip();
        bool is_valid() const;
    private:
        string street;
        char state[2];
        string city;
        string street_num;
        string zip;
};