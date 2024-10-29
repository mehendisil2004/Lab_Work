#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    ~Point() {}

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }

    double operator-(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(3.0, 4.0);
    Point p2(6.0, 8.0);

    cout << "Point 1: ";
    p1.display();
    cout << "\nPoint 2: ";
    p2.display();

    double distance = p1 - p2;
    cout << "\nDistance between points: " << distance << endl;

    return 0;
}
