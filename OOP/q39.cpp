#include <iostream>

using namespace std;

class INT {
private:
    int i;

public:
    INT(int a = 0) : i(a) {}

    ~INT() {}

    INT& operator++() {
        ++i;
        return *this;
    }

    INT operator++(int) {
        INT temp = *this;
        ++i;
        return temp;
    }

    operator int() const {
        return i;
    }

    INT& operator=(const INT& other) {
        if (this != &other) {
            i = other.i;
        }
        return *this;
    }

    INT& operator=(int value) {
        i = value;
        return *this;
    }
};

int main() {
    int x = 3;
    INT y = x;
    y++ = ++y;
    x = y;
    cout << "Final value of x: " << x << endl;  
    return 0;
}
