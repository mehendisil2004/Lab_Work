#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular linked list with 'n' nodes
struct Node* createCircularLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* tail = NULL;

    for (int i = 1; i <= n; i++) {
        struct Node* newNode = createNode(i);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head; // Make it circular
    return head;
}

// Function to solve the Josephus problem
int josephusProblem(struct Node** head, int k) {
    struct Node* prev = NULL;
    struct Node* current = *head;

    // Traverse the list until only one node is left
    while (current->next != current) {
        // Move to the k-th node
        for (int count = 1; count < k; count++) {
            prev = current;
            current = current->next;
        }

        // Remove the k-th node
        printf("Eliminating: %d\n", current->data);
        prev->next = current->next;
        free(current);
        current = prev->next;
    }

    // The last remaining node is the solution
    *head = current;
    return current->data;
}

// Main function to demonstrate the Josephus problem solution
int main() {
    int n, k;

    // Input the number of people and the step value
    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    // Create the circular linked list
    struct Node* head = createCircularLinkedList(n);

    // Solve the Josephus problem
    int survivor = josephusProblem(&head, k);
    printf("The survivor is person: %d\n", survivor);

    return 0;
}
