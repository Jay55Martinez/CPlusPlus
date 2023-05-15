// Jay Martinez - Assignment1 q2 - 5/15/23
// edit to see if you made the right investment selling the mona lisa for 11 
// with different interest rates 2% to 12%

// Fig. 5.6: fig05_06.cpp
// Compound interest calculations with for.
#include <iostream>
#include <iomanip>
#include <cmath> // standard math library
using namespace std;

int main()
{
   double amount; // amount on deposit at end of each year
   double principal = 11.0; // initial amount before interest (the value of mona lisa)
   double rate = .02; // annual interest rate 

   // display headers
   cout << "Rate" << setw( 41 ) << "Amount worth after 397 Years" << endl;

   // set floating-point number format
   cout << fixed << setprecision( 2 );

   // calculate amount after 397 years with different rates from 2% - 12%
   for (rate; rate <= .125; rate+=.005)
   {
      // calculate new amount for specified year
      amount = principal * pow( 1.0 + rate, 397);

      // display the year and the amount
      cout << rate*100 << setw( 41 ) << amount << endl;

   } // end for 
} // end main


/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/