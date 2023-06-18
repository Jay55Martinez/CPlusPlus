// Debug T-2
// Function template finds biggest of two or three objects. The function works on any data type which has greater than operator defined.
/*
List of fixes:
made the template agruments all T
fixed constructor
changed the sign > to < in find biggest to work
operator<< was changed to operator>
*/
#include <iostream>
#include <string>
using namespace std;

template <class T>
void findBiggest(T a, T b, T c)
{
   T large = a;
   if (b > large)
      large = b;
   if (c > large)
      large = c;
   cout << "The largest of " << a << ", " << b << ", and " << c << " is " << large << endl;
}

template <class T>
void findBiggest(T a, T b)
{
   T large = a;
   if (b > large)
      large = b;
   cout << "The larger of " << a << " and " << b << " is " << large << endl;
}

class BankAccount
{
   friend ostream &operator<<(ostream &, const BankAccount &);

private:
   string name;
   int amount;

public:
   BankAccount(const string& name, const int amount);
   bool operator>(const BankAccount &) const;
   string get_name() const { return this->name; }
   int get_amount() const { return this->amount; }
};

BankAccount::BankAccount(const string &name, const int amount)
{
   this->name = name;
   this->amount = amount;
}

ostream &operator<<(ostream &out, const BankAccount &bh)
{
   out << "Name: " <<  bh.get_name() << ", Amount: " << bh.get_amount() << endl;
   return out;
}

bool BankAccount::operator>(const BankAccount &bh) const
{
   return amount > bh.amount;
}

int main()
{
   BankAccount bAA("A", 800);
   BankAccount bAB("B", 120);
   BankAccount bAC("C", 500);
   findBiggest(bAA, bAB);
   findBiggest(bAB, bAC);
   findBiggest(bAC, bAA);
   findBiggest(bAA, bAB, bAC);
   return 0;
}
