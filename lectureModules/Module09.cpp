#include <iostream>
#include <bitset>
#include <limits>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

/*
Different Types of Streams (IO, File, Strings)
- Standard IO (cin cout)
Input Validation:
- Standard input (cin) returns the reference of the input stream. It will be valid if the value is 
is valid. But if it not valid then it will throw an (error or EOF). (which is treated as false)
-- review https://www.cplusplus.com/reference/ios/ios/fail/
-- cin.good() -> goodbit -> true if all error flags are 0
-- cin.eof() -> eofbit -> if eof is reached. Cntl+D (Mac, Linux), Cntl+Z (windows)
-- cin.fail() -> failbit -> incorerct format, stream may be valid
-- cin.bad() -> badbit -> unrecoverable damaged input.
if bad bit is true, fail is also true.
-> Recommendation is: check the bad bit first then check for fail bit.
-- rdstate() rerurns flag: [BadBit, Failbit, EOFBit, Goodbit]
- String Stream library is useful as well (tokenization)
- We have also talked about <cstdlib> which offers options for string
conversions (C library) such as atoi, atof, etc. C++ version of these
is actually part of <string> library are those are stoi, stof,
to_string(), etc.
- File Stream: Always check if file was open successfully or not. It
should be in same folder as executable. specify path of your file
"c:\\files\\in.txt"
- Standard Output (cout) can be configured for diaplying values in
specific formats.
-- Chapter 13 of Detel book
-- setbase(), hex, oct, dec can also set the base
-- fixed or scientific notation
-- serprecisoin -> number of digits on the right of for in FP number
-- fill or setfill to specify padding  character -> default space
-- width or setw to minimum width
-- showpoint - show trailing zeros
-- left, right, internal alignment - left right justify
Reminder some flags are sticky (they presist throught the program) while
others are not sticky (they retain the effect for the following line of code and then
get reset)
- almost all flags are sticky except stdw
*/

int main() {

    // style in c++ for reading valid inputs
    /*
    int x;
    if (cin>>x) {
        cout<<x<<endl;
    }
    else 
        cout<<"input error"<<endl;
    */

    /*
    int x;
    cin>>x;
    bitset<4>f_val(cin.rdstate());
    cout<<f_val<<endl;
    */

    /*
    int x=0;
    while(true){
        cout<<"enter a number: "<<endl;
        cin>>x;
        if(cin.good()){ break; }
        else if(cin.bad()) {cout<<"unrecoverable error"<<endl; return EXIT_FAILURE;}
        else if(cin.eof()) {cout<<"good bye!"<<endl; return EXIT_SUCCESS;}
        else if(cin.fail()) {
        cout<<"Please try again!"<<endl;
            //return EXIT_FAILURE;
            cin.clear(); //clear flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush istream
        }
        else {cout<<"unknown error"<<endl; return EXIT_FAILURE;}
    }
    cout<<"number is: "<<x<<endl;
    */

    /*
    istringstream istr("1 2 3 4");
    //string str = "1 2 3 4"; istringstream istr(str);
    int i;
    while(istr >> i) {
        cout<<i<<endl;
    }

    ostringstream ostr;
    for(int i=0; i<4; i++) {
        ostr<<i<<",";
    }
    cout<<ostr.str()<<endl;
    */
    
    /*
    string input = "abc,def,ghi";
    istringstream ss(input);
    string words;
    char token = ',';

    while(getline(ss, words, token)){
        cout<<words<<"\n";
    }
    */

    //how to write and read files
    /*
    ifstream infile("in.txt");
    //fstream file_name; file_name.open("in.txt", ios:in);
    if(!infile) {
        cout<<"can't open file"<<endl;
        return EXIT_FAILURE;
    }
    ofstream outfile("out.txt");
    if(!outfile) {
        cout<<"can't open the file"<<endl;
        return EXIT_FAILURE;
    }
    string line;
    while(outfile && getline(infile, line)) {
        cout<<line<<endl;
        outfile<<line<<endl;
    }
    */

    ios_base::fmtflags orig_flag = cout.flags(); //save them

    double x;
    while(cin>>x) {
        cout.fill('#');
        cout<<setprecision(2)<<fixed<<right<<setw(10)<<x<<endl;
        //change .. configure
    }

    cout.flags(orig_flag);

    return EXIT_SUCCESS;
}