#include <iostream>

using namespace std;

class Demo {
private:
    int a;
    mutable int b;

public:
    Demo(int x, int y) : a(x), b(y) {}

    int getA() const {
        return a;
    }

    int getB() const {
        return b;
    }

    void modifyB(int newValue) const {
        b = newValue;
    }
};

int main() {
    Demo obj(10, 20);

     cout << "a: " << obj.getA() <<  endl;
     cout << "b: " << obj.getB() <<  endl;

    obj.modifyB(30);
     cout << "b after modification: " << obj.getB() <<  endl;

    return 0;
}