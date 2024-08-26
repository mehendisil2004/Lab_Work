#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head,float co,int ex) {
    struct node* temp;
    struct node* new= malloc(sizeof(struct node));
    new->coeff=co;
    new->expo=ex;
    new->link=NULL;
    if(head==NULL || ex> head->expo)
    {
        new->link=head;
        head=new;
    }
    else
    {
        temp=head;
        while(temp->link !=NULL && temp->link->expo>=ex)
        {
            temp=temp->link;
        }
        new->link=temp->link;
        temp->link=new;
    }
    return head;
}

void print(struct node* head) {
    if(head == NULL) {
        printf("No Polynomial");
    }
    else {
        struct node* temp = head;
        while(temp != NULL) {
            printf("%dx^%d", temp->coeff, temp->expo);
            temp = temp->link;
            if(temp != NULL) printf (" + ");
            else printf("\n");
            }
    }
}

struct node* multi(struct node* head,struct node* head1) {
    struct node* temp=head;
    struct node* temp1=head1;
    struct node* head2=NULL;
    
    if(head == NULL || head1 == NULL) {
        printf("Zero Polynomial");
    }

    while(temp != NULL) {
        while(temp1 != NULL) {
            head2 = insert(head2, temp-> coeff * temp1 ->coeff, temp->expo + temp1->expo);
            temp1 = temp1->link;
        }
        temp = temp->link;
        temp1 = head1;
    }
    print(head2);
}


struct node* create(struct node* head) {
    int n, i, expo;
    float coeff;
    
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficient of term %d: ",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent of term %d: ",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    printf("\n");
    return head;
}

int main() {
    struct node* head=NULL;
    struct node* head1=NULL;
    
    printf("Enter first Polynomial \n");
    head=create(head);
    printf("Enter second Polynomial \n");
    head1=create(head1);

    multi(head, head1);
    return 0;
}