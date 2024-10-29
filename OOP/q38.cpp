#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) out << " + " << c.imag << "i";
        else out << " - " << -c.imag << "i";
        return out;
    }
};

class Quadratic {
private:
    double a, b, c;

public:
    Quadratic(double a = 0.0, double b = 0.0, double c = 0.0) : a(a), b(b), c(c) {}

    Quadratic operator+(const Quadratic& other) const {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    friend istream& operator>>(istream& in, Quadratic& q) {
        cout << "Enter coefficient for x^2 (a): ";
        in >> q.a;
        cout << "Enter coefficient for x (b): ";
        in >> q.b;
        cout << "Enter constant term (c): ";
        in >> q.c;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Quadratic& q) {
        out << q.a << "x^2 ";
        if (q.b >= 0) out << "+ " << q.b << "x ";
        else out << "- " << -q.b << "x ";
        
        if (q.c >= 0) out << "+ " << q.c;
        else out << "- " << -q.c;
        
        return out;
    }

    double evaluate(double x) const {
        return (a * x * x) + (b * x) + c;
    }

    void computeRoots() const {
        double discriminant = b * b - 4 * a * c;
        
        if (discriminant > 0) {  
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots are real and distinct: " << root1 << " and " << root2 << endl;
        } else if (discriminant == 0) {  
            double root = -b / (2 * a);
            cout << "Roots are real and identical: " << root << " and " << root << endl;
        } else {  
            double realPart = -b / (2 * a);
            double imagPart = sqrt(-discriminant) / (2 * a);
            Complex root1(realPart, imagPart);
            Complex root2(realPart, -imagPart);
            cout << "Roots are complex: " << root1 << " and " << root2 << endl;
        }
    }
};

int main() {
    Quadratic q1, q2;
    cout << "Enter first polynomial (q1):" << endl;
    cin >> q1;
    cout << "\nEnter second polynomial (q2):" << endl;
    cin >> q2;

    Quadratic q3 = q1 + q2;
    cout << "\nq1 + q2 = " << q3 << endl;

    double x;
    cout << "\nEnter a value of x to evaluate q1: ";
    cin >> x;
    cout << "q1(" << x << ") = " << q1.evaluate(x) << endl;

    cout << "\nRoots of q1:" << endl;
    q1.computeRoots();

    return 0;
}
