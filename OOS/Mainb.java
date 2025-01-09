class Stack {
    private int[] stackArray; 
    private int top;          
    private int capacity;    

    public Stack(int size) {
        stackArray = new int[size];
        capacity = size;
        top = -1;
    }

    public void push(int value) {
        if (top == capacity - 1) {
            System.out.println("Stack Overflow! Cannot push " + value);
        } else {
            stackArray[++top] = value;
        }
    }

    public int pop() {
        if (top == -1) {
            System.out.println("Stack Underflow! Stack is empty.");
            return -1;
        } else {
            return stackArray[top--];
        }
    }

    public void print() {
        if (top == -1) {
            System.out.println("Stack is empty.");
        } else {
            System.out.print("Stack elements: ");
            for (int i = 0; i <= top; i++) {
                System.out.print(stackArray[i] + " ");
            }
            System.out.println();
        }
    }
}

public class Mainb {
    public static void main(String[] args) {
        Stack stack = new Stack(30);

        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(15);
        stack.push(9);

        System.out.println("Stack after pushes-");
        stack.print();

        stack.pop();
        stack.pop();
        stack.pop();

        System.out.println("Stack after popping three elements-");
        stack.print();
    }
}
