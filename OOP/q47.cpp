#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int maxSize;

public:
    class StackOverflowException {
    public:
        const char* what() const { return "Stack Overflow: Cannot push onto a full stack."; }
    };

    class StackUnderflowException {
    public:
        const char* what() const { return "Stack Underflow: Cannot pop from an empty stack."; }
    };

    Stack(int size) : maxSize(size), top(-1) {
        arr = new int[maxSize];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top >= maxSize - 1) {
            throw StackOverflowException();
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    int pop() {
        if (top < 0) {
            throw StackUnderflowException();
        }
        int poppedValue = arr[top--];
        cout << "Popped " << poppedValue << " from the stack." << endl;
        return poppedValue;
    }

    int peek() const {
        if (top < 0) {
            throw StackUnderflowException();
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == maxSize - 1;
    }
};

int main() {
    Stack myStack(3); 
    
    try {
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        
        myStack.push(40);
    }
    catch (const Stack::StackOverflowException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    try {
        cout << "Top element is: " << myStack.peek() << endl;
        
        myStack.pop();
        myStack.pop();
        myStack.pop();

        myStack.pop();
    }
    catch (const Stack::StackUnderflowException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
