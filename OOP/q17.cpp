#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double length=0.0, double width=0.0) : length(length), width(width) {}

    double area()
    {
        return length*width;
    }
};

int main() {
    double length, width;

    cin >> length >> width;

    Rectangle rect(length, width);

    cout << "Area = " << rect.area() << endl;

    return 0;
}
