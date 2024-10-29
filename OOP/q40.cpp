#include <iostream>

using namespace std;

class IntArray {
private:
    int* arr;
    int size;

public:
    IntArray(int s) : size(s) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;  
        }
    }

    ~IntArray() {
        delete[] arr;
    }

    int& operator[](int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            cout << "Index out of bounds" << endl;
            exit(1); 
        }
    }

    friend ostream& operator<<(ostream& out, const IntArray& iArray) {
        for (int i = 0; i < iArray.size; i++) {
            out << iArray.arr[i] << " ";
        }
        return out;
    }
};

int main() {
    IntArray i(10);
    for (int k = 0; k < 10; k++) {
        i[k] = k;
    }
    cout << i;
    return 0;
}
