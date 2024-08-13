#include <bits/stdc++.h>
using namespace std;

class Point3D
{
private:
    double x;
    double y;
    double z;

public:
    Point3D();
    Point3D(double x, double y, double z);
    static double distance(Point3D, Point3D);
};

Point3D::Point3D()
{
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Point3D::Point3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point3D::distance(Point3D p1, Point3D p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main() {
    double x1, y1, z1, x2, y2, z2;

    cin >> x1 >> y1 >> z1;

    cin >> x2 >> y2 >> z2;

    Point3D p1(x1, y1, z1);
    Point3D p2(x2, y2, z2);

    cout << "Distance = " << Point3D::distance(p1, p2) << endl;

    return 0;
}