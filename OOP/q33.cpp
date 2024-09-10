#include <iostream>
#include <cmath>
using namespace std;

class Shape2D
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape2D() {}
};

class Circle : public Shape2D
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    double area() const override
    {
        return M_PI * radius * radius;
    }

    double perimeter() const override
    {
        return 2 * M_PI * radius;
    }

    double getRadius() const
    {
        return radius;
    }
};

class Rectangle : public Shape2D
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    double area() const override
    {
        return length * width;
    }

    double perimeter() const override
    {
        return 2 * (length + width);
    }
};

int main()
{
    Shape2D* shapes[5];

    Circle circle1(5.0);  
    Circle circle2(10.0); 
    Circle circle3(7.5);  

    Rectangle rectangle1(4.0, 6.0); 
    Rectangle rectangle2(3.0, 8.0); 

    shapes[0] = &circle1;
    shapes[1] = &circle2;
    shapes[2] = &circle3;
    shapes[3] = &rectangle1;
    shapes[4] = &rectangle2;

    for (int i = 0; i < 5; ++i)
    {
        cout << "Shape " << (i + 1) << " :" << endl;
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;
        cout<<endl;
    }

    return 0;
}
