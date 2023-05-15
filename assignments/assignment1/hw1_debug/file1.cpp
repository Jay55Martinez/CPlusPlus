/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

/*
List of bugs:
- scope for many functions were not defined
- limit set to 0 should be set to 10
- even_product and odd_product set to 0 should be set to 1
- if statement to check even used (/) divide rather than (%) remainder
- if statement to check odd is not needed becasue it is even or not
- the line that set the sum should be out of the for loop
- cout for the sum was not factored correctly
- The for loop for the alternate characters was an infinate loop
*/
#include <iostream>
using namespace std;

int main(){
    int limit = 10, even_product = 1, odd_product = 1, sum;
    char c;
    
    cout<<"The value of limit is "<<limit<<endl;

    // loop multiplies the even and odd numbers repectively
    for(int i = 1; i <= limit; i++) { 
        // checks if even
        if(i % 2 == 0) {
            even_product *= i; // multiply all evens
        }   
        else {
            odd_product *= i; // multiply all odds
        }
    }
    
    // sum of the the even and odd products
    sum = even_product + odd_product;
    cout<<"The Sum = "<<sum<<endl;

    // loop prints out alternate characters from 'A' to 'Z'
    for(c = 'Z'; c > 'A'; c-=2) {
        if(c == 'B') {
            cout<<c<<endl;
            break;
        }
    	cout<<c<<" ";
    }
    
    return 0;
}
