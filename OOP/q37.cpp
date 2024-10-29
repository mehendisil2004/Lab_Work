#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:  
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex& operator=(const Complex& other) {
        if (this != &other) {  
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        if (denom == 0) {
            cerr << "Error: Division by zero" << endl;
            return Complex();
        }
        return Complex((real * other.real + imag * other.imag) / denom,
                       (imag * other.real - real * other.imag) / denom);
    }

    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i";
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);
    
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;

    cout << "c1 = ";
    c1.display();
    cout << "\nc2 = ";
    c2.display();

    cout << "\n\nc1 + c2 = ";
    c3.display();

    cout << "\nc1 - c2 = ";
    c4.display();

    cout << "\nc1 * c2 = ";
    c5.display();

    cout << "\nc1 / c2 = ";
    c6.display();

    return 0;
}
