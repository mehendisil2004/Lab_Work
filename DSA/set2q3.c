#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specified position
void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Function to delete a node from a specified position
void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse print the linked list
void reversePrint(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    // Go to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Print in reverse order
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Function to reverse the doubly linked list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // If the list is not empty, set the head to the last node
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the operations
int main() {
    struct Node* head = NULL;

    // Insert nodes at specific positions
    insertNode(&head, 10, 0);  // Insert 10 at position 0
    insertNode(&head, 20, 1);  // Insert 20 at position 1
    insertNode(&head, 30, 2);  // Insert 30 at position 2
    insertNode(&head, 40, 1);  // Insert 40 at position 1

    printf("Original list: \n");
    printList(head);

    // Count the number of nodes
    printf("Number of nodes: %d\n", countNodes(head));

    // Reverse print the doubly linked list
    printf("Reverse print: \n");
    reversePrint(head);

    // Delete a node from a specific position
    deleteNode(&head, 2);  // Delete node at position 2
    printf("List after deleting node at position 2: \n");
    printList(head);

    // Reverse the doubly linked list
    reverseList(&head);
    printf("Reversed list: \n");
    printList(head);

    return 0;
}
