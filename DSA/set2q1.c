#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
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

// Function to insert a node at a specified position
void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
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
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
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

// Helper function for reverse printing the linked list
void reversePrintHelper(struct Node* head) {
    if (head == NULL)
        return;
    reversePrintHelper(head->next);
    printf("%d -> ", head->data);
}

// Function to reverse print the linked list
void reversePrint(struct Node* head) {
    reversePrintHelper(head);
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse the current node
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    *head = prev;
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

    // Inserting nodes at specific positions
    insertNode(&head, 10, 0);  // Insert 10 at position 0
    insertNode(&head, 20, 1);  // Insert 20 at position 1
    insertNode(&head, 30, 2);  // Insert 30 at position 2
    insertNode(&head, 40, 1);  // Insert 40 at position 1

    printf("Original list: \n");
    printList(head);

    // Counting the number of nodes
    printf("Number of nodes: %d\n", countNodes(head));

    // Reverse printing the linked list
    printf("Reverse print: \n");
    reversePrint(head);

    // Deleting a node from a specific position
    deleteNode(&head, 2);  // Delete node at position 2
    printf("List after deleting node at position 2: \n");
    printList(head);

    // Reversing the linked list
    reverseList(&head);
    printf("Reversed list: \n");
    printList(head);

    return 0;
}
