#include <iostream>
#include <random>
#include <vector>
using namespace std;
/*
1. Inheritance is commonly used to define "commonality". That becomes a canidate for base class.
Interfaces in java are basically a similar idea that common functions are placed in a interface
which then can be implemented by different classes.
2. Child classes inherit public and protected members of the parent class except constructors/destructors.
3. Child classes have two parts (they are made up of two parts). Those are: Rollable part from partent class
and then Coin or Die part from child class
4. Since child object consists of two parts, we call the constructor of both classe: first for the child then
for the parent based on the order we defined in the initialization list.
5. If you remove the rollable constructor delegation in Dio or Coin class, it throws an error
because it expects a default constructor for Rollable. Coompiler didn't write the default constructor because
you wrote an overloaded constructor. 
6. Inheritance allows child classes to add more code (features or extersions)
in child classes.
7. Open-Close Principle: which means that it is open for extension, closed for modification.
The idea is that you extend classes rather than modify old classes. However, limitation of using too much inheritance
is child classes become too much dependent on parent class. this is called "tight coupling". This rule has been 
updated to recommend using more interfaces than inheritance. Advantage is that you introduce another layer of abstraction.
Interface in java is similar to abstract classes in c++.
8. Remember that protected members are accessible only in the classes itself and the child classes.
9. We have redefined roll function in child classes, it not same as polymorphism.
10. Polymorphism is complire looks at type of object at run time and then uses the appropriate
implementatin (or version of) the function to call. This idea is known as dynamic dispatch or dynamic lookup.
Currently the code is using "Compile time" or "static binding" instead of dunaic binding or late binding. When
you redefine functions, whatever is the type at compile time is what is used unless you specifically use polymorphism.
11. To make your code polymorphic use the key word "virtual". virtual keyword carrys over to child class but
it is a good practice to always use it inside them.
12. c++ has a keyword "override" which is used to ask the compiler if you can verify/confirm that you
are infact overriding.
13. Another principle that is worth mentioning here is substitution principle: you can always use an object
of a subclass when an object of a super class is expected. In other words, a reference of type "parent"
can always store a reference of type "child". Since child has parent part in it. This is commonly know as
Liskov Substitution Principle. This is related to the idea of how we extend classes. it promtes that child classs should
not be very different that parent class (they should use same interface) to not have old code break.
14. As part of polymorphism remember to define destructors as virtual.
15. If you pass the argument to roll_n "by value" then we know that compiler makes a copy. By assigning a 
Coin to a Rollable type, you lose the Coin part and are left with just Rollable part. This is know as 
object slicing. Solution is to use pointers or pass by reference or pass by pointers 
16. Abstract class: is a class with at least 1 pure virual function. A pure function is a function = 0
You can't instantiate an Abstract class. Child must override pure virtaul functions unless they are defined with
"final" keyword
17. Denerally we prefer to write code that is generic and it could have different behavors for different type.
We prefer using polymorphism to choose athe approprate type of code we would like to use.
18. WE don't want to look at the type at compile time to decide whci implementation to use.
This is known as "Sependency INversion" which says write code that does not depend on dynamic_cast.
Instead write generic code.
*/

// Coin and a Dice. Common: abiliy to roll
class Rollable{
    private:
        const string m_name;
    protected:
        int random(int upto) const { return 1+rand()%upto; }
    public:
        Rollable(const string& name) : m_name(name) {}
        const string& get_name() const { return m_name; }
        // virtual int roll() const { return 0; }
        virtual int roll() const = 0; 
        // virtual int roll() const final = 0; //childern can't override anymore
        virtual ~Rollable() {}
};

class Coin : public Rollable {
    public:
        Coin() : Rollable("Coin") {}
        virtual int roll() const override { return  random(2); }
        virtual ~Coin() {}
};

class Die : public Rollable {
    private:
        int m_sides;
    public:
        Die(int sides) : Rollable("d" + to_string(sides)), m_sides(sides) {}
        virtual int roll() const override { return  random(m_sides); }
        virtual ~Die() {}
};

void roll_n(const Rollable& r, int n) {
    cout<<r.get_name()<<" was rolled"<<endl;
    for(int i = 0; i < n; i++) 
        cout<<r.roll()<<" ";
    cout<<endl;
}

void check_coin(const Rollable& r) {
    try {
    const Coin& c = dynamic_cast<const Coin&>(r);
    cout<<"was a coin"<<endl;
    } catch(bad_cast &e) {
        cout<<"was not a coin"<<endl;
    }
}

int main(void) {
    srand(time(nullptr));
    Die d6(6);
    Coin c;

    roll_n(d6, 5);
    roll_n(c, 5);

    check_coin(d6);
    check_coin(c);

    // cout<<d6.get_name()<<endl;
    // cout<<c.get_name()<<endl;
    // cout<<d6.roll()<<endl;
    // cout<<c.roll()<<endl;

    // cout<<c.random(2)<<endl; // not allowed because funtion is protected
    // Rollable r; // not allowedc if Rollable is an Abstract class
    Rollable &r1 = d6;
    cout<<r1.roll()<<endl;

    cout<<"Bye"<<endl;
    return 0;
}