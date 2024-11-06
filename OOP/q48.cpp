#include <iostream>
#include <stdexcept>
using namespace std;

class Motor {
public:
    Motor() {
        throw runtime_error("Motor error: Motor failed to start.");
    }
};

class Car {
private:
    Motor motor; 
public:
    Car() try : motor() { 
        cout << "Car successfully initialized with motor." << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught in Car constructor: " << e.what() << endl;
        throw; 
    }
};

class Garage {
private:
    Car car; 
public:
    Garage() try : car() { 
        cout << "Garage successfully initialized with car." << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught in Garage constructor: " << e.what() << endl;
        throw logic_error("Garage error: Failed to initialize car due to motor trouble.");
    }
};

int main() {
    try {
        Garage garage; 
    } catch (const logic_error& e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

    return 0;
}
