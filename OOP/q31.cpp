#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    float height;

public:
    Person(string name, int age, float height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }

    string getName() { return name; }
    int getAge() { return age; }
    float getHeight() { return height; }

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setHeight(float height) { this->height = height; }

    virtual void printDetails() 
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Height: " << height << " meters" << endl;
    }
};

class Student : public Person
{
private:
    int roll;
    int yearOfAdmission;

public:
    Student(string name, int age, float height, int roll, int yearOfAdmission)
        : Person(name, age, height)
    {
        this->roll = roll;
        this->yearOfAdmission = yearOfAdmission;
    }

    int getRoll() { return roll; }
    int getYearOfAdmission() { return yearOfAdmission; }

    void setRoll(int roll) { this->roll = roll; }
    void setYearOfAdmission(int yearOfAdmission) { this->yearOfAdmission = yearOfAdmission; }

    void printDetails() override
    {
        Person::printDetails(); 
        cout << "Roll Number: " << roll << endl;
        cout << "Year of Admission: " << yearOfAdmission << endl;
    }
};

int main()
{
    Person p1("Riri", 40, 1.75);
    Person p2("Siri", 35, 1.65);

    Student s1("Alice", 20, 1.68, 12345, 2023);
    Student s2("Milley", 22, 1.80, 54321, 2022);

    Person* people[4];
    
    people[0] = &p1;
    people[1] = &p2;
    people[2] = &s1;
    people[3] = &s2;

    for (int i = 0; i < 4; ++i)
    {
        people[i]->printDetails(); 
        cout << endl;
    }

    return 0;
}
