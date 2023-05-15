// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 617, exchange = 424
Output : 
"I am calling to tell you to buy a subscription to Dogs Monthly Magazine!"
617-424-0001
617-424-0002
617-424-0003
...
617-424-9998
617-424-9999
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

/*
List of bugs:
- scope for iostream were missing on many functions
- asked for area code took in exchange
- asked for exchange took in area code
- area code was incorrectly initalized with camal casing rather than snake casing
- digits should be ints not chars
- nested loop did not work as intended
- printed Hello and Complete statements to many times
*/
#include<iostream>
  
int main(){
    int digit1, digit2, digit3 = 0, digit4 = 0, area_code, exchange;

    std::cout<<"Hello, I am a telemarketing calling making program.\n";
    // enter area code 
    std::cout<<"Enter a three-digit area code ";
    std::cin>>area_code;
    // ender exchange
    std::cout<<"Enter a three-digit exchange to call ";
    std::cin>>exchange;

    std::cout<< "I am calling to tell you to buy a subscription to Dogs Monthly!\n";

    // loop prints all the different number endings 0000, 0001, ...
    for(digit1 = 0; digit1 < 10; ++digit1) {
        for(digit2 = 0; digit2 < 10; ++digit2) {
            while(digit3 < 10) {
                do {
                    std::cout<< "Dialing ("<<area_code<<")"<<"-"<<exchange<<"-";
                    std::cout<<digit1<<digit2<<digit3<<digit4<<std::endl;
                    digit4++;
                } while(digit4 < 10);
                digit3++;
                digit4 = 0;
            }
            digit3 = 0;
        }
    }

    std::cout<< "\nCalls completed"<<std::endl;
    return 0;
    }
