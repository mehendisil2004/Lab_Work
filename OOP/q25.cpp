#include <iostream>
using namespace std;

class Queue {
private:
    int* data;
    int front, rear;
    int maxSize;
    int itemCount;

public:
    Queue(int size) : maxSize(size), front(-1), rear(-1), itemCount(0) {
        data = new int[maxSize];
    }

    ~Queue() {
        delete[] data;
    }

    void add(int value) {
        if (isFull()) {
            cout << "Queue overflow! Cannot add " << value << endl;
        } else {
            rear = (rear + 1) % maxSize;
            data[rear] = value;
            if (front == -1) front = 0;  
            itemCount++;
        }
    }

    int remove() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot remove element" << endl;
            return -1;  
        } else {
            int removedValue = data[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % maxSize;
            }
            itemCount--;
            return removedValue;
        }
    }

    void disp() {
            cout << "Queue elements: ";
            int i = front;
            do {
                cout << data[i] << " ";
                i = (i + 1) % maxSize;
            } while (i != (rear + 1) % maxSize);
            cout << endl;
        }

    bool isFull() const {
        return itemCount == maxSize;
    }

    bool isEmpty() const {
        return itemCount == 0;
    }
};

int main() {
    Queue queue(10);  

    queue.add(2);
    queue.add(3);
    queue.add(4);
    queue.add(5);

    cout << "Removed element: " << queue.remove() << endl;
    cout << "Removed element: " << queue.remove() << endl;

    queue.disp();

    return 0;
}
