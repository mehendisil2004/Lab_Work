#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float img;

public:
    void setReal(float real) {
        this->real = real;
    }

    void setImg(float img) {
        this->img = img;
    }

    float getReal() {
        return real;
    }

    float getImg() {
        return img;
    }

    void disp() {
        cout << real << " + " << img << "i" << endl;
    }

    Complex sum(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.img = img + c.img;
        return result;
    }
};

int main() {
    Complex c1, c2, c3;

    c1.setReal(3.5);
    c1.setImg(2.5);

    c2.setReal(1.5);
    c2.setImg(4.5);

    c3 = c1.sum(c2);

    cout << "First complex number: ";
    c1.disp();

    cout << "Second complex number: ";
    c2.disp();

    cout << "Sum of the two complex numbers: ";
    c3.disp();

    return 0;
}
