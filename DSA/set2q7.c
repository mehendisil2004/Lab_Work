#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure using array
typedef struct {
    int items[MAX];
    int front, rear;
} ArrayQueue;

// Initialize the queue
void initializeArrayQueue(ArrayQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isArrayQueueEmpty(ArrayQueue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isArrayQueueFull(ArrayQueue *q) {
    return q->rear == MAX - 1;
}

// Insert an element into the queue
void insertArrayQueue(ArrayQueue *q, int value) {
    if (isArrayQueueFull(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->items[++(q->rear)] = value;
    printf("%d inserted into queue\n", value);
}

// Delete an element from the queue
void deleteArrayQueue(ArrayQueue *q) {
    if (isArrayQueueEmpty(q)) {
        printf("Queue underflow\n");
        return;
    }
    printf("%d deleted from queue\n", q->items[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

// Check the number of elements in the queue
int countArrayQueueElements(ArrayQueue *q) {
    if (isArrayQueueEmpty(q)) {
        return 0;
    }
    return q->rear - q->front + 1;
}

void arrayQueueMenu() {
    ArrayQueue q;
    initializeArrayQueue(&q);

    int choice, value;

    do {
        printf("\nArray Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Check Number of Elements\n");
        printf("4. Check Overflow\n");
        printf("5. Check Underflow\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertArrayQueue(&q, value);
                break;
            case 2:
                deleteArrayQueue(&q);
                break;
            case 3:
                printf("Number of elements in queue: %d\n", countArrayQueueElements(&q));
                break;
            case 4:
                if (isArrayQueueFull(&q)) {
                    printf("Queue is full (Overflow condition)\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 5:
                if (isArrayQueueEmpty(&q)) {
                    printf("Queue is empty (Underflow condition)\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 6:
                printf("Exiting Array Queue Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}


// Node structure for linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Queue structure using linked list
typedef struct {
    Node *front, *rear;
} LinkedListQueue;

// Initialize the queue
void initializeLinkedListQueue(LinkedListQueue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isLinkedListQueueEmpty(LinkedListQueue *q) {
    return q->front == NULL;
}

// Insert an element into the queue
void insertLinkedListQueue(LinkedListQueue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d inserted into queue\n", value);
}

// Delete an element from the queue
void deleteLinkedListQueue(LinkedListQueue *q) {
    if (isLinkedListQueueEmpty(q)) {
        printf("Queue underflow\n");
        return;
    }
    Node *temp = q->front;
    printf("%d deleted from queue\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

// Check the number of elements in the queue
int countLinkedListQueueElements(LinkedListQueue *q) {
    Node *temp = q->front;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void linkedListQueueMenu() {
    LinkedListQueue q;
    initializeLinkedListQueue(&q);

    int choice, value;

    do {
        printf("\nLinked List Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Check Number of Elements\n");
        printf("4. Check Overflow (Not applicable for Linked List)\n");
        printf("5. Check Underflow\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertLinkedListQueue(&q, value);
                break;
            case 2:
                deleteLinkedListQueue(&q);
                break;
            case 3:
                printf("Number of elements in queue: %d\n", countLinkedListQueueElements(&q));
                break;
            case 4:
                printf("Overflow is not applicable for Linked List Queue\n");
                break;
            case 5:
                if (isLinkedListQueueEmpty(&q)) {
                    printf("Queue is empty (Underflow condition)\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 6:
                printf("Exiting Linked List Queue Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}


int main() {
    int choice;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Array Implementation\n");
        printf("2. Linked List Implementation\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arrayQueueMenu();
                break;
            case 2:
                linkedListQueueMenu();
                break;
            case 3:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}