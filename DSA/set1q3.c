#include <stdio.h>
#include <stdlib.h>

struct node {
    float co;             // Coefficient
    int expo;             // Exponent
    struct node* link;    // Link to next term
};

// Function to insert a new term in descending order of exponents
struct node* insert(struct node* head, float co, int expo) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->co = co;
    temp->expo = expo;
    temp->link = NULL;

    if (head == NULL || head->expo < expo) {
        temp->link = head;
        head = temp;
    } else {
        struct node* temp1 = head;
        while (temp1->link != NULL && temp1->link->expo >= expo) {
            temp1 = temp1->link;
        }
        temp->link = temp1->link;
        temp1->link = temp;
    }
    return head;
}

// Function to add two polynomials
struct node* add(struct node* head1, struct node* head2) {
    struct node* head3 = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->expo == head2->expo) {
            head3 = insert(head3, head1->co + head2->co, head1->expo);
            head1 = head1->link;
            head2 = head2->link;
        } else if (head1->expo > head2->expo) {
            head3 = insert(head3, head1->co, head1->expo);
            head1 = head1->link;
        } else {
            head3 = insert(head3, head2->co, head2->expo);
            head2 = head2->link;
        }
    }

    while (head1 != NULL) {
        head3 = insert(head3, head1->co, head1->expo);
        head1 = head1->link;
    }
    while (head2 != NULL) {
        head3 = insert(head3, head2->co, head2->expo);
        head2 = head2->link;
    }

    return head3;
}

// Function to create a polynomial
struct node* create(struct node* head) {
    int n, expo;
    float co;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%f", &co);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, co, expo);
    }

    return head;
}

// Function to display the polynomial
void display(struct node* head) {
    struct node* temp = head;

    if (temp == NULL) {
        printf("0\n");
        return;
    }

    while (temp != NULL) {
        if (temp->co > 0 && temp != head) {
            printf("+");
        }
        printf("%.1fx^%d", temp->co, temp->expo);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;

    printf("Create first polynomial:\n");
    head1 = create(head1);
    printf("First Polynomial: ");
    display(head1);

    printf("\nCreate second polynomial:\n");
    head2 = create(head2);
    printf("Second Polynomial: ");
    display(head2);

    head3 = add(head1, head2);
    printf("\nResultant Polynomial after Addition: ");
    display(head3);

    return 0;
}
