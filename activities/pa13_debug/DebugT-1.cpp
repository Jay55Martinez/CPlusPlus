// Debug T-1
// Function template adds objects. The function works on any object which has '+' opertor defined.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)
/*
Lists of fixes:
fixed the add template functions.
added getters to the person class
made the + operator actual add the ages rather than subtract
*/
#include <iostream>
#include <string>
using namespace std;

template <class T>
T add(T x, T y)
{
   T sum;
   sum = x + y;
   return sum;
}

class Person
{
   friend ostream &operator<<(ostream &, const Person &);

private:
   string lastName;
   string firstName;
   int age;

public:
   void setValues(string, string, int);
   Person operator+(Person);
   string get_last() { return this->lastName; }
   string get_first() { return this->firstName; }
   int get_age() { return this-> age; }
};

ostream &operator<<(ostream &out, Person &per)
{
   out << per.get_first()<< " " << per.get_last() << " " << per.get_age() << " years old" << endl;
   return out;
}

void Person::setValues(string last, string first, int age)
{
   lastName = last;
   firstName = first;
   age = age;
}

Person Person::operator+(Person p)
{
   Person temp;
   temp.lastName = "of Age";
   temp.firstName = "Sum";
   age = p.age + temp.age;
   return temp;
}

int main()
{
   int a = 7, b = 26, c;
   double d = 39.25, e = 2.01, f;
   Person g, h, i;
   g.setValues("Mitchell", "Donald", 40);
   h.setValues("Clayton", "Rita", 35);
   c = add(a, b);
   f = add(d, e);
   i = add(g, h);
   cout << c << endl;
   cout << f << endl;
   cout << i << endl;
   return 0;
}
