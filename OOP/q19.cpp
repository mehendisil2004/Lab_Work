#include <bits/stdc++.h>
using namespace std;

class Vector {
private:
    vector<int> data;

public:
    Vector() = default;

    Vector(const vector<int>& vec) : data(vec) {}

    Vector operator+(const Vector& other) const {
        vector<int> result(data.size());
        transform(data.begin(), data.end(), other.data.begin(), result.begin(), plus<int>());
        return Vector(result);
    }

    Vector operator-(const Vector& other) const {
        vector<int> result(data.size());
        transform(data.begin(), data.end(), other.data.begin(), result.begin(), minus<int>());
        return Vector(result);
    }

    bool operator==(const Vector& other) const {
        return data == other.data;
    }

    bool operator<(const Vector& other) const {
        return data < other.data;
    }

    bool operator>(const Vector& other) const {
        return data > other.data;
    }

    void disp() const {
        for (const auto& element : data) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
        Vector v1({1, 2, 3});
        Vector v2({4, 5, 6});

        Vector v3 = v1 + v2;
        Vector v4 = v2 - v1;

        cout << "v1: ";
        v1.disp();

        cout << "v2: ";
        v2.disp();

        cout << "v3 (v1 + v2): ";
        v3.disp();

        cout << "v4 (v2 - v1): ";
        v4.disp();

        cout << "v1 == v2: " << (v1 == v2) << endl;
        cout << "v1 < v2: " << (v1 < v2) << endl;
        cout << "v1 > v2: " << (v1 > v2) << endl;

    return 0;
}
