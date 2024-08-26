#include <iostream>
#include <algorithm>
using namespace std;

class IntArray {
private:
    int* arr;      
    int size;    

public:
    IntArray(int size) : size(size) {
        arr = new int[size];
        fill(arr, arr + size, 0);
    }

    IntArray(initializer_list<int> list) : size(list.size()) {
        arr = new int[size];
        copy(list.begin(), list.end(), arr);
    }

    IntArray(const IntArray& other) : size(other.size) {
        arr = new int[size];
        copy(other.arr, other.arr + size, arr);
    }

    ~IntArray() {
        delete[] arr;
    }

    IntArray& operator=(const IntArray& other) {
        if (this == &other) return *this;  

        delete[] arr;  
        size = other.size;
        arr = new int[size];
        copy(other.arr, other.arr + size, arr);
        return *this;
    }

    IntArray operator+(const IntArray& other) const {
        if (size != other.size) throw invalid_argument("Arrays must be of the same size for addition");
        IntArray result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }

    void reverseArray() {
        reverse(arr, arr + size);
    }

    void sortArray() {
        sort(arr, arr + size);
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    IntArray arr1 = {1, 2, 3};
    cout << "arr1 elements: ";
    arr1.print();

    IntArray arr2 = arr1;
    cout << "arr2 (copy of arr1) elements: ";
    arr2.print();

    arr2.reverseArray();
    cout << "arr2 elements after reversing: ";
    arr2.print();

    cout << "arr1 elements after reversing arr2: ";
    arr1.print();

    return 0;
}
