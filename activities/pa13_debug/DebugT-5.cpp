// The goal of this debug execrice is to understand the concept of object slicing.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

// Expected output -
// Name: tesla model Year: 2019
// Name: Hyundai model Year: 2020 Mileage: 23
// Name: Ford model Year: 2012 Miles driven: 20000
// Name: Ford model Year: 2017 Miles driven: 10000
/*
List of bugs: 
fix constructor for car
operator= was not using reference
printCarInfo was not using reference
*/
#include <iostream>
using namespace std;

// Base class: car
class car
{
private:
    string name;
    int modelYear;

protected:
    void assign(const car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
    }

public:
    car(const string &n, const int my) : name(n), modelYear(my) {}

    string get_name() const { return name; }
    int get_modelYear() const { return modelYear; }

    virtual void print() const
    {
        cout << "Name: " << name << " Model Year: " << modelYear << endl;
    }

    virtual const car &operator=(const car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
        return *this;
    }
};

// Derived class: sedan
class sedan : public car
{
private:
    int mileage;

public:
    sedan(const string &n, const int my, const int m) : car(n, my), mileage(m) {}

    void print() const override
    {
        cout << "Name: " << get_name() << " Model Year: " << get_modelYear() << " Mileage: " << mileage << endl;
    }
};

// Derived class: suv
class suv : public car
{
private:
    int miles;

public:
    suv(const string &n, const int my, const int m) : car(n, my), miles(m) {}

    void print() const override
    {
        cout << "Name: " << get_name() << " Model Year: " << get_modelYear() << " Miles driven: " << miles << endl;
    }

    const suv &operator=(const car &c) override
    {
        if (const suv *b = dynamic_cast<const suv *>(&c))
        {
            assign(*b);
        }
        return *this;
    }
};

// Function to print car information
void printCarInfo(const car &c)
{
    c.print();
}

int main()
{
    // Create car objects
    car tesla = car("Tesla", 2019);
    sedan hyundai = sedan("Hyundai", 2020, 23);
    suv ford = suv("Ford", 2012, 20000);

    // Print car information
    printCarInfo(tesla);
    printCarInfo(hyundai);

    // Reference to the base class pointing to a derived class object
    car &ref = ford;
    printCarInfo(ref);

    // Create another suv object
    suv ford2 = suv("Ford", 2017, 10000);
    ref = ford2;

    // Print updated car information
    printCarInfo(ref);

    return 0;
}


