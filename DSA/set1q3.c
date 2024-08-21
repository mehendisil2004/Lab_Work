#include<stdio.h>
#include<stdlib.h>

struct node {
    int co;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head,float co,int expo) {
    struct node* temp=malloc(sizeof(struct node));
    temp->co=co;
    temp->expo=expo;
    temp->link=NULL;
    if(head==NULL || head->expo<expo)
    {
        temp->link=head;
        head=temp;
    }
    else
    {
        struct node* temp1=head;
        while(temp1->link!=NULL && temp1->link->expo>=expo)
        {
            temp1=temp1->link;
        }
        temp->link=temp1->link;
        temp1->link=temp;
    }
    return head;
}

struct node* add(struct node* head,struct node* head1) {
    struct node* temp=head;
    struct node* temp1=head1;
    struct node* head2=NULL;
    
    while(temp!=NULL && temp1!=NULL)
    {
        if(temp->expo==temp1->expo)
        {
            head2=insert(head2,temp->co+temp1->co,temp->expo);
            temp=temp->link;
            temp1=temp1->link;
        }
        else if(temp->expo>temp1->expo)
        {
            head2=insert(head2,temp->co,temp->expo);
            temp=temp->link;
        }
        else if(temp1->expo>temp->expo)
        {
            head2=insert(head2,temp1->co,temp1->expo);
            temp1=temp1->link;
        }
    }
    while(temp!=NULL)
    {
        head2=insert(head2,temp->co,temp->expo);
        temp=temp->link;
    }
    while(temp1!=NULL)
    {
        head2=insert(head2,temp1->co,temp1->expo);
        temp1=temp1->link;
    }
    return head2;
}


struct node* create(struct node* head) {
    int n,expo;
    float co;
    
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficient of term %d: ",i+1);
        scanf("%f",&co);
        printf("Enter the exponent of term %d: ",i+1);
        scanf("%d",&expo);
        head=insert(head,co,expo);
    }
    printf("\n");
    return head;
}

int main() {
    struct node* head=NULL;
    struct node* head1=NULL;
    struct node* head2=NULL;
    head=create(head);
    head1=create(head1);
    head2=add(head,head1); 
    struct node* ptr=head2;
    while(ptr!=NULL)
    {
        printf("(%.1fx^%d)",ptr->co,ptr->expo);
        ptr=ptr->link;
        if(ptr!=NULL)
        {
            printf("+");
        }
        else
        printf("\n");  
    }
}