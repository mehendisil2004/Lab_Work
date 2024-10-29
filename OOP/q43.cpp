#include <iostream>

using namespace std;

class Index {
private:
    int value;

public:
    Index(int v = 0) : value(v) {}

    operator int() const {
        return value;
    }

    Index& operator=(int v) {
        value = v;
        return *this;
    }

    int operator+(const Index& other) const {
        return value + other.value;
    }
};

class Integer {
private:
    int value;

public:
    Integer(int v = 0) : value(v) {}

    Integer& operator=(const Index& idx) {
        value = idx;  
        return *this;
    }

    operator int() const {
        return value;
    }

    friend ostream& operator<<(ostream& out, const Integer& obj) {
        out << obj.value;
        return out;
    }
};

int main() {
    Index in(4), out(10);

    int x = in;       
    int y = in + out; 

    in = 2;           

    Integer i;
    i = in;           

    cout << "x = " << x << ", y = " << y << ", in = " << int(in) << ", i = " << i << endl;

    return 0;
}
