#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle();
    Rectangle(double length, double width);
    double area() const;
};

Rectangle::Rectangle()
{
    this->length = 0.0;
    this->width = 0.0;
}

Rectangle::Rectangle(double length, double width)
{
    this->length = length;
    this->width = width;
}

double Rectangle::area() const
{
    return length*width;
}

int main() {
    double length, width;

    cin >> length >> width;

    Rectangle rect(length, width);

    cout << "Area = " << rect.area() << endl;

    return 0;
}