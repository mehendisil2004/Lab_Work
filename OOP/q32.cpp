#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    double salary;

public:
    Employee(string name, double salary)
    {
        this->name = name;
        this->salary = salary;
    }

    string getName() { return name; }
    double getSalary() { return salary; }

    void setName(string name) { this->name = name; }
    void setSalary(double salary) { this->salary = salary; }

    virtual void printDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: Rs." << salary << endl;
    }

    virtual ~Employee() {}
};

class Manager : public Employee
{
private:
    string type;
    double allowance;

public:
    Manager(string name, double salary, string type, double allowance)
        : Employee(name, salary)
    {
        this->type = type;
        this->allowance = allowance;
    }

    string getType() { return type; }
    double getAllowance() { return allowance; }

    void setType(string type) { this->type = type; }
    void setAllowance(double allowance) { this->allowance = allowance; }

    void printDetails() override
    {
        Employee::printDetails();
        cout << "Type: " << type << endl;
        cout << "Allowance: Rs." << allowance << endl;
    }

    double getTotalSalary()
    {
        return salary + allowance;
    }
};

class Clerk : public Employee
{
private:
    double allowance;

public:
    Clerk(string name, double salary, double allowance)
        : Employee(name, salary)
    {
        this->allowance = allowance;
    }

    double getAllowance() { return allowance; }
    void setAllowance(double allowance) { this->allowance = allowance; }

    void printDetails() override
    {
        Employee::printDetails();
        cout << "Allowance: Rs." << allowance << endl;
    }

    double getTotalSalary()
    {
        return salary + allowance;
    }
};

int main()
{
    Employee emp1("Ruby", 50000);
    Employee emp2("Jane", 55000);

    Manager mgr1("Riri", 70000, "Senior Manager", 10000);
    Manager mgr2("Siri", 75000, "Assistant Manager", 8000);

    Clerk clerk1("Alexa", 30000, 2000);
    Clerk clerk2("Alice", 32000, 2500);

    Employee* employees[6];

    employees[0] = &emp1;
    employees[1] = &emp2;
    employees[2] = &mgr1;
    employees[3] = &mgr2;
    employees[4] = &clerk1;
    employees[5] = &clerk2;

    double totalSalary = 0;

    for (int i = 0; i < 6; ++i)
    {
        employees[i]->printDetails();
        cout << endl;

        Manager* mPtr = dynamic_cast<Manager*>(employees[i]);
        Clerk* cPtr = dynamic_cast<Clerk*>(employees[i]);

        if (mPtr)
        {
            totalSalary += mPtr->getTotalSalary();
        }
        else if (cPtr)
        {
            totalSalary += cPtr->getTotalSalary();
        }
        else
        {
            totalSalary += employees[i]->getSalary();
        }
    }

    cout << "Total Salary of all employees: Rs." << totalSalary << endl;

    return 0;
}
