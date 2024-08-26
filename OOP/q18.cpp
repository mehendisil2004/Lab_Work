#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double distance(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

class WirelessDevice {
private:
    static int idCounter;  
    int id;
    Point location;
    double range;

public:
    WirelessDevice(double range = 10.0) : id(++idCounter), range(range) {
        location = Point(rand() % 100, rand() % 100);
    }

    const Point& getLocation() const {
        return location;
    }

    double getRange() const {
        return range;
    }

    void move() {
        location = Point(rand() % 100, rand() % 100);
    }

    bool isNeighbor(const WirelessDevice& other) const {
        return location.distance(other.getLocation()) <= range;
    }

    int getId() const {
        return id;
    }
};

int WirelessDevice::idCounter = 0;

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    vector<WirelessDevice> devices(10);

    cout << "Initial neighbors for each device:" << endl;
    for (int i = 0; i < devices.size(); ++i) {
        cout << "Device " << devices[i].getId() << " neighbors: ";
        for (int j = 0; j < devices.size(); ++j) {
            if (i != j && devices[i].isNeighbor(devices[j])) {
                cout << devices[j].getId() << " ";
            }
        }
        cout << endl;
    }

    cout << "\nAfter moving devices to new locations:" << endl;
    for (auto& device : devices) {
        device.move();
    }

    for (int i = 0; i < devices.size(); ++i) {
        cout << "Device " << devices[i].getId() << " neighbors: ";
        for (int j = 0; j < devices.size(); ++j) {
            if (i != j && devices[i].isNeighbor(devices[j])) {
                cout << devices[j].getId() << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
