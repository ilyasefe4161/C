#include<stdio.h>
#include<stdlib.h>

struct node {
    int number;
    struct node * next;
};

struct node* addbegin(struct node *head, int num){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->number=num;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;
}

struct node* addlast(struct node *head, int num){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->number=num;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else{
        struct node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
    return head;
}

void printList(struct node *head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->number);
        temp=temp->next;
    }
}

int main(){
    int n;
    struct node *head=NULL;
    while(n!=-1){
        printf("enter a number for adding a linked list: ");
        scanf("%d",&n);
        int nn=(n%10);
        if(nn%2==1)
            head=addbegin(head,n);
        else
            head=addlast(head,n);
    }
    printList(head);
    return 0;
}
