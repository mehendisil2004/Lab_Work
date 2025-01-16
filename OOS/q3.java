class stack {
    int[] arr;
    int top;

    stack(int size) {
        arr = new int[size];
        top = -1;
    }

    void push(int val) {
        arr[++top]= val;
    }

    int pop() {
        return arr[top--];
    }

    void print() {
        for (int i = 0; i <= top; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}

class main {
    public static void main(String[] args) {
        stack s = new stack(30);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(15);
        s.push(9);
        s.print();
        s.pop();
        s.pop();
        s.pop();
        s.print();
    }
}
