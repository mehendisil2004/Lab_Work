#include <bits/stdc++.h>
using namespace std;

class Point3D
{
private:
    double x, y, z;

public:
    Point3D(double x=0, double y=0, double z=0) : x(x), y(y), z(z) {}

    double distance(Point3D p1, Point3D p2)
    {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
    }
};

int main() {
    double x1, y1, z1, x2, y2, z2;

    cin >> x1 >> y1 >> z1;

    cin >> x2 >> y2 >> z2;

    Point3D p1(x1, y1, z1);
    Point3D p2(x2, y2, z2);

    cout << "Distance = " << p2.distance(p1, p2) << endl;

    return 0;
}
