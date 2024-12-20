#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Structure for a stack
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Push element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow.\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        return -1; // Return -1 for underflow
    }
    return stack->arr[stack->top--];
}

// Peek the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // Return -1 if stack is empty
    }
    return stack->arr[stack->top];
}

// Queue structure using two stacks
typedef struct Queue {
    Stack stack1;
    Stack stack2;
} Queue;

// Initialize the queue
void initQueue(Queue* queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

// Enqueue operation
void enqueue(Queue* queue, int value) {
    push(&queue->stack1, value);
}

// Dequeue operation
int dequeue(Queue* queue) {
    if (isEmpty(&queue->stack2)) {
        while (!isEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }

    if (isEmpty(&queue->stack2)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 to indicate empty queue
    }

    return pop(&queue->stack2);
}

// Get the front element of the queue
int front(Queue* queue) {
    if (isEmpty(&queue->stack2)) {
        while (!isEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }

    if (isEmpty(&queue->stack2)) {
        printf("Queue is empty. Cannot access front element.\n");
        return -1; // Return -1 to indicate empty queue
    }

    return peek(&queue->stack2);
}

// Check if the queue is empty
bool isQueueEmpty(Queue* queue) {
    return isEmpty(&queue->stack1) && isEmpty(&queue->stack2);
}

// Main function to test the queue
int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    enqueue(&queue, 40);
    printf("Front element: %d\n", front(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    if (isQueueEmpty(&queue)) {
        printf("Queue is empty.\n");
    }

    return 0;
}
