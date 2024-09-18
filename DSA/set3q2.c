#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int searchInOrder(int in[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (in[i] == value) {
            return i;
        }
    }
    return -1;
}

struct Node* buildTree(int in[], int pre[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    int current = pre[*preIndex];
    (*preIndex)++;
    struct Node* node = createNode(current);

    if (inStart == inEnd) {
        return node;
    }

    int inIndex = searchInOrder(in, inStart, inEnd, current);

    node->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    node->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return node;
}

void inorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

void preorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

int main() {
    int inOrder[] = {4, 2, 5, 1, 6, 3, 7};  
    int preOrder[] = {1, 2, 4, 5, 3, 6, 7}; 
    int len = sizeof(inOrder) / sizeof(inOrder[0]);

    int preIndex = 0;
    struct Node* root = buildTree(inOrder, preOrder, 0, len - 1, &preIndex);

    printf("In-order traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal of the tree: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
