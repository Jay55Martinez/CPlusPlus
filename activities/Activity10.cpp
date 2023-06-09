// Jay Martinez -- Activity 10 -- 6/9/23
/* 
class Group which includes:
- group's name, group number, focus area or responsibility, and a list of employees of that group

class Employee which includes: 
- employee name, unique email, designation, and which group they are member of

UML Diagram in ASCII:

        +-------------------------------------------------+
        |        Group                                    |
        +-------------------------------------------------+
        | - group_name: string                            |
        | - bio: string                                   |
        | - group_num: int                                |
        | - employees: vector<Employee*>                  |
        +-------------------------------------------------+
        | + Group()                                       |
        | + Group(string, string, int, vector<Employee*>) |
        | + get_name(): string                            |
        | + get_bio(): string                             |
        | + get_num(): int                                |
        | + get_employees(): vector<Employee*>            |
        | + set_name(string)                              |
        | + set_bio(string)                               |
        | + set_num(int)                                  |
        | + set_employee(Employee*)                       |
        | + operator-(const int&): Group                  |
        | + operator+(const Group&): Group                |
        +-------------------------------------------------+

                              ^
                              |
            +--------------------------------------+
            |                Employee              |
            +--------------------------------------+
            | - emp_name: string                   |
            | - email: string                      |
            | - designation: string                |
            | - group: Group*                      |
            +--------------------------------------+
            | + Employee()                         |
            | + Employee(string, string, string)   |
            | + get_name(): string                 |
            | + get_email(): string                |
            | + get_designation(): string          |
            | + get_group(): Group*                |
            | + set_name(string)                   |
            | + set_email(string)                  |
            | + set_designation(string)            |
            | + set_group(Group*)                  |
            +--------------------------------------+


*/
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;

// forward declaration
class Group;
class Employee;

// class Group
class Group {
    public:
    // Constructors: 
    // default constructor using delegation
    Group() : Group("", "", 0, {}) {};
    // non-default constructor
    Group(string name, string response, int num, vector<Employee*> employee) {
        this->group_name = name;
        this->bio = response;
        this->group_num = num;
        this->employees = employee;
    }

    //getters:
    string get_name() { return this->group_name; } // in-line
    string get_bio() { return this->bio; } // in-line
    int get_num() { return this->group_num; } // in-line
    vector<Employee*> get_employees() { return this->employees; }

    //setters:
    void set_name(string name) { this->group_name = name; } // in-line
    void set_bio(string b) { this->bio = b; } // in-line
    void set_num(int n) {this->group_num = n; } // in-line
    void set_employee(Employee* e) { this->employees.push_back(e); } // in-line

    // overloaded operators:
    Group operator-(const int& value) {
        Group temp;
        temp.set_bio(this->bio);
        temp.set_name(this->group_name);
        temp.set_num(this->group_num);
        // Check if the employees vector has enough elements
        if (value <= this->employees.size()) {
            // Add a deep copy of the employees to the temp object
            for (int i = 0; i < this->employees.size() - value; i++) {
                temp.set_employee(this->employees.at(i));
            }
        } 
        else {
            // Handle the case where value exceeds the number of employees
            throw invalid_argument("cant subtract more that the number of employees");
        }
        return temp;
    }

    Group operator+(const Group& second) {
        Group temp = *this;
        for (auto emp : second.employees) {
            temp.employees.push_back(emp);
        }
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Group& group);
    friend istream& operator>>(istream& in, Group& group);


    private:
    string group_name;
    string bio; // responsibility
    int group_num;
    vector<Employee*> employees;
};

// class Employee
class Employee {
    public:
    // Constructors: 
    // default constructor using delegation
    Employee() : Employee("", "", "") {};
    // non-default constructor
    Employee(string name, string email, string designation) {
        this->emp_name = name;
        this->email = email;
        this->designation = designation;
    }
    
    // getter funtions for employee
    string get_name() { return this->emp_name; } // in-line
    string get_email() { return this->email; } //in-line
    string get_designation() { return this->designation; } //in-line
    Group* get_group() { return this->group; } //in-line

    // setter function for employee
    void set_name(string name) { this->emp_name = name; } // in-line
    void set_email(string e) { this->email = e; } // in-line
    void set_designation(string d) { this->designation = d; } // in-line
    void set_group(Group* g) { this->group = g; } // in-line

    // operators:
    friend ostream& operator << (ostream& out, const Employee& emp);
    friend istream& operator >> (istream& in, Employee& emp);



    private: 
    string emp_name;
    string email;
    string designation;
    Group* group;
};

// friend definition Employee
ostream& operator << (ostream& out, const Employee& emp) {
    out<<emp.emp_name<<" "<<emp.designation<<" "<<emp.email<<" "<<emp.group->get_name()<<endl;
    return out;
}

// friend definition Employee
istream& operator >> (istream& in, Employee& emp) {
    cout<<"enter employee name:"<<endl;
    getline(in, emp.emp_name);
    cout<<"enter employee email:"<<endl;
    getline(in, emp.email);
    cout<<"enter employee designation"<<endl;
    getline(in, emp.designation);
    return in;
}

istream& operator>>(istream& in, Group& group) {
    cout << "Enter group name: ";
    getline(in, group.group_name);
    cout << "Enter group number: ";
    string num;
    getline(in, num);
    group.group_num = stoi(num);
    cout << "Enter group bio: ";
    getline(in, group.bio);

    // Read employees
    int numEmployees;
    cout << "Enter the number of employees: ";
    in >> numEmployees;
    in.ignore();  // Ignore the newline character after reading the integer
    for (int i = 0; i < numEmployees; i++) {
        Employee* emp = new Employee();
        in >> *emp;
        emp->set_group(&group);
        group.set_employee(emp);
    }

    return in;
}

// not in-line definition Group
ostream& operator<<(ostream& out, const Group& group) {
    std::for_each(group.employees.begin(), group.employees.end(), [&] (Employee* emp) { 
        out<<*emp;
    });
    return out;
}

int main(void) {
    // initialization
    // creating employees without group
    Employee* emp1 = new Employee("Bill", "Bfireman@work.com", "cheif");
    Employee* emp2 = new Employee("John", "Jfireman@work.com", "driver");
    Employee* emp3 = new Employee("Olivia", "Ofireman@work.com", "operator");
    Employee* emp4 = new Employee("Emily", "Epolice@work.com", "patrol");
    Employee* emp5 = new Employee("Scott", "Spolice@work.com", "cheif");
    Employee* emp6 = new Employee("Liam", "Lpolice@work.com", "patrol");
    Employee* emp7 = new Employee("Josh", "Jems@work.com", "driver");
    Employee* emp8 = new Employee("Ian", "Iems@work.com", "responder");

    // creating set of employees for the group
    vector<Employee*> firemen = {emp1, emp2, emp3};
    vector<Employee*> police = {emp4, emp5, emp6};
    vector<Employee*> ems = {emp7, emp8};

    // creating the groups
    Group* fire_dept = new Group("Fire Department", "respond to fire emergencies", 9, firemen);
    Group* police_dept = new Group("Police Department", "maintain order and peace", 12, police);
    Group* ems_dept = new Group("Emergency Service", "provide medical support", 4, ems);

    // setting the groups that the employees are part of
    emp1->set_group(fire_dept);
    emp2->set_group(fire_dept);
    emp3->set_group(fire_dept);
    emp4->set_group(police_dept);
    emp5->set_group(police_dept);
    emp6->set_group(police_dept);
    emp7->set_group(ems_dept);
    emp8->set_group(ems_dept);

    // testing the << operator
    cout<<"(<<):"<<endl;
    cout<<*fire_dept;
    cout<<*emp1;


    // testing the (-) operation
    cout<<"(-):"<<endl;
    Group lay_offs_fire_dept = *fire_dept - 2;
    cout<<lay_offs_fire_dept;

    // testing the (>>) operation
    cout<<"(>>):"<<endl;
    Group g;
    cin>>g;
    cout<<g;

    // testing the (+) operation
    cout<<"(+):"<<endl;
    Group emergency = *fire_dept + *police_dept + *ems_dept;
    cout<<emergency;

    delete emp1;
    delete emp2;
    delete emp3;
    delete emp4;
    delete emp5;
    delete emp6;
    delete emp7;
    delete emp8;

    delete fire_dept;
    delete police_dept;
    delete ems_dept;

    return 0;
}