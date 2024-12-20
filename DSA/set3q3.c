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

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void findPreSuc(struct TreeNode* root, struct TreeNode** pre, struct TreeNode** suc, int key) {
    if (root == NULL) {
        return;
    }

    if (root->data == key) {
        if (root->left != NULL) {
            *pre = root->left;
            while ((*pre)->right != NULL) {
                *pre = (*pre)->right;
            }
        }

        if (root->right != NULL) {
            *suc = root->right;
            while ((*suc)->left != NULL) {
                *suc = (*suc)->left;
            }
        }
        return;
    }

    if (key < root->data) {
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else { 
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct TreeNode* root = NULL;
    int choice, key;
    struct TreeNode *pre = NULL, *suc = NULL;

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert a key\n");
        printf("2. Search a key\n");
        printf("3. Find in-order predecessor and successor\n");
        printf("4. Delete a key\n");
        printf("5. Display in-order traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key inserted!\n");
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("Key found in the tree.\n");
                } else {
                    printf("Key not found.\n");
                }
                break;

            case 3:
                printf("Enter key to find predecessor and successor: ");
                scanf("%d", &key);
                pre = suc = NULL;
                findPreSuc(root, &pre, &suc, key);
                if (pre != NULL) {
                    printf("Predecessor: %d\n", pre->data);
                } else {
                    printf("No predecessor found.\n");
                }
                if (suc != NULL) {
                    printf("Successor: %d\n", suc->data);
                } else {
                    printf("No successor found.\n");
                }
                break;

            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Key deleted!\n");
                break;

            case 5:
                printf("In-order traversal of the tree: ");
                inOrder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 6);

    return 0;
}