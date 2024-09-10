#include <iostream>
using namespace std;

class Base {
public:
    // Non-virtual destructor
    ~Base() {
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    // Creating a derived class object, but using a base class pointer
    Base* obj = new Derived();

    // Deleting the object through the base class pointer
    delete obj;  // Only Base destructor will be called, Derived destructor won't be called!

    return 0;
}
