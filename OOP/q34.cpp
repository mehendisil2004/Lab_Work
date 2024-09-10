#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
using namespace std;

class Shape
{
public:
    virtual ~Shape() {}

    virtual void printName() const = 0;
};

class TwoDShape : public Shape
{
public:
    virtual double getArea() const = 0;

    void printName() const override
    {
        cout << "TwoDShape: ";
    }
};

class ThreeDShape : public Shape
{
public:
    virtual double getArea() const = 0;

    virtual double getVolume() const = 0;

    void printName() const override
    {
        cout << "ThreeDShape: ";
    }
};

class Circle : public TwoDShape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override
    {
        return M_PI * radius * radius;
    }

    void printName() const override
    {
        cout << "Circle" << endl;
    }
};

class Triangle : public TwoDShape
{
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() const override
    {
        return 0.5 * base * height;
    }

    void printName() const override
    {
        cout << "Triangle" << endl;
    }
};

class Ellipse : public TwoDShape
{
private:
    double majorAxis, minorAxis;

public:
    Ellipse(double a, double b) : majorAxis(a), minorAxis(b) {}

    double getArea() const override
    {
        return M_PI * majorAxis * minorAxis;
    }

    void printName() const override
    {
        cout << "Ellipse" << endl;
    }
};

class Sphere : public ThreeDShape
{
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}

    double getArea() const override
    {
        return 4 * M_PI * radius * radius;
    }

    double getVolume() const override
    {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }

    void printName() const override
    {
        cout << "Sphere" << endl;
    }
};

class Cube : public ThreeDShape
{
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double getArea() const override
    {
        return 6 * side * side;
    }

    double getVolume() const override
    {
        return pow(side, 3);
    }

    void printName() const override
    {
        cout << "Cube" << endl;
    }
};

int main()
{
    vector<shared_ptr<Shape>> shapes;

    shapes.push_back(make_shared<Circle>(5.0));
    shapes.push_back(make_shared<Triangle>(4.0, 6.0));
    shapes.push_back(make_shared<Ellipse>(3.0, 2.0));

    shapes.push_back(make_shared<Sphere>(4.0));
    shapes.push_back(make_shared<Cube>(3.0));

    for (const auto& shape : shapes)
    {
        shape->printName();

        if (auto twoDShape = dynamic_cast<TwoDShape*>(shape.get()))
        {
            cout << "Area: " << twoDShape->getArea() << endl;
        }
        else if (auto threeDShape = dynamic_cast<ThreeDShape*>(shape.get()))
        {
            cout << "Surface Area: " << threeDShape->getArea() << endl;
            cout << "Volume: " << threeDShape->getVolume() << endl;
        }

        cout << endl;
    }

    return 0;
}
