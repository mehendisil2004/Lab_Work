#include <iostream>

using namespace std;

class Integer {
private:
    int value;

public:
    Integer(int v = 0) : value(v) {}

    Integer(const Integer& other) : value(other.value) {}

    Integer operator++(int) {
        Integer temp = *this;
        value++;
        return temp;
    }

    Integer operator+(const Integer& other) const {
        return Integer(value + other.value);
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
    Integer a = 4, b = a, c;
    c = a + b++;
    int i = a;
    cout << a << " " << b << " " << c;
    return 0;
}
