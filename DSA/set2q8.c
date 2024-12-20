#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Structure for Circular Queue using Array
typedef struct {
    int front, rear, size;
    int arr[MAX];
} CircularQueueArray;

// Initialize the circular queue
void initializeQueueArray(CircularQueueArray* q) {
    q->front = q->rear = -1;
    q->size = 0;
}

// Check if the queue is full
int isFullArray(CircularQueueArray* q) {
    return (q->size == MAX);
}

// Check if the queue is empty
int isEmptyArray(CircularQueueArray* q) {
    return (q->size == 0);
}

// Enqueue operation
void enqueueArray(CircularQueueArray* q, int value) {
    if (isFullArray(q)) {
        printf("Queue is full (Overflow).\n");
        return;
    }
    if (isEmptyArray(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->arr[q->rear] = value;
    q->size++;
}

// Dequeue operation
void dequeueArray(CircularQueueArray* q) {
    if (isEmptyArray(q)) {
        printf("Queue is empty (Underflow).\n");
        return;
    }
    printf("Dequeued: %d\n", q->arr[q->front]);
    q->front = (q->front + 1) % MAX;
    q->size--;
    if (isEmptyArray(q)) {
        q->front = q->rear = -1;
    }
}

// Display the queue
void displayQueueArray(CircularQueueArray* q) {
    if (isEmptyArray(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX) {
        printf("%d ", q->arr[i]);
    }
    printf("%d\n", q->arr[i]);
}

// Circular Queue Using Linked List

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} CircularQueueLinkedList;

// Initialize the circular queue
void initializeQueueLinkedList(CircularQueueLinkedList* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

// Check if the queue is empty
int isEmptyLinkedList(CircularQueueLinkedList* q) {
    return (q->size == 0);
}

// Enqueue operation
void enqueueLinkedList(CircularQueueLinkedList* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmptyLinkedList(q)) {
        q->front = q->rear = newNode;
        q->rear->next = q->front;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }
    q->size++;
}

// Dequeue operation
void dequeueLinkedList(CircularQueueLinkedList* q) {
    if (isEmptyLinkedList(q)) {
        printf("Queue is empty (Underflow).\n");
        return;
    }
    Node* temp = q->front;
    printf("Dequeued: %d\n", temp->data);

    if (q->front == q->rear) {
        free(temp);
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    q->size--;
}

// Display the queue
void displayQueueLinkedList(CircularQueueLinkedList* q) {
    if (isEmptyLinkedList(q)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    CircularQueueArray arrayQueue;
    CircularQueueLinkedList listQueue;

    initializeQueueArray(&arrayQueue);
    initializeQueueLinkedList(&listQueue);

    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue (Array)\n");
        printf("2. Dequeue (Array)\n");
        printf("3. Display (Array)\n");
        printf("4. Enqueue (Linked List)\n");
        printf("5. Dequeue (Linked List)\n");
        printf("6. Display (Linked List)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue (Array): ");
                scanf("%d", &value);
                enqueueArray(&arrayQueue, value);
                break;
            case 2:
                dequeueArray(&arrayQueue);
                break;
            case 3:
                displayQueueArray(&arrayQueue);
                break;
            case 4:
                printf("Enter value to enqueue (Linked List): ");
                scanf("%d", &value);
                enqueueLinkedList(&listQueue, value);
                break;
            case 5:
                dequeueLinkedList(&listQueue);
                break;
            case 6:
                displayQueueLinkedList(&listQueue);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}