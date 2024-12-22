#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* buildTree(int inOrder[], int preOrder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    int current = preOrder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = createNode(current);

    if (inStart == inEnd) {
        return root;
    }

    int inIndex = search(inOrder, inStart, inEnd, current);

    root->left = buildTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);

    return root;
}

void printInOrder(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int main() {
    int n;

    // Input the size of the arrays
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    int inOrder[n], preOrder[n];

    // Input the inorder traversal
    printf("Enter the inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inOrder[i]);
    }

    // Input the preorder traversal
    printf("Enter the preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preOrder[i]);
    }

    int preIndex = 0;
    struct TreeNode* root = buildTree(inOrder, preOrder, 0, n - 1, &preIndex);

    printf("The tree is: ");
    printInOrder(root);
    printf("\n");

    return 0;
}
