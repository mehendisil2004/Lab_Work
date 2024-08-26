#include <iostream>
using namespace std;

class Stack {
private:
    int* buffer;
    int top;
    int maxSize;

public:
    Stack(int size) : maxSize(size), top(-1) {
        buffer = new int[maxSize];
    }

    ~Stack() {
        delete[] buffer;
    }

    void push(int value) {
        if (top >= maxSize - 1) {
            cout << "Stack overflow!" << value << endl;
        } else {
            buffer[++top] = value;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow!" << endl;
            return -1;  
        } else {
            return buffer[top--];
        }
    }

    void disp() {       
        cout << "Stack elements: " << endl;
            for (int i = top; i >= 0; --i) {
                cout << buffer[i] << " ";
            }
            cout << endl;
    }
};

int main() {
    Stack stack(10);  

    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << "Popped element: " << stack.pop() << endl;

    stack.disp();

    return 0;
}
