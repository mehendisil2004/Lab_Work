#include <iostream>
#include <stdexcept>
using namespace std;

enum Direction { LEFT, RIGHT };
enum Status { STOPPED, RUNNING };

class Vehicle {
public:
    Status status;
    Direction direction;

    Vehicle(Status s, Direction d) : status(s), direction(d) {}
};

class CollisionException : public exception {
public:
    const char* what() const noexcept override {
        return "Collision alert: Two vehicles running in opposite directions in the same lane!";
    }
};

class Lane {
public:
    void checkForCollision(const Vehicle& v1, const Vehicle& v2) {
        if (v1.status == RUNNING && v2.status == RUNNING && v1.direction != v2.direction) {
            throw CollisionException();
        }
    }
};

int main() {
    Vehicle vehicle1(RUNNING, LEFT);
    Vehicle vehicle2(RUNNING, RIGHT);

    Lane lane;

    try {
        lane.checkForCollision(vehicle1, vehicle2);
        cout << "No collision: Vehicles are moving safely." << endl;
    } 
    catch (const CollisionException& e) {
        cout << "Exception caught: " << e.what() << endl;
        cout << "Taking action to avoid collision: Slowing down vehicles or stopping one." << endl;
    }

    return 0;
}
