#include<stdio.h>
#include<stdlib.h>

struct node {
    int number;
    struct node * next;
};

struct node* changeFirstAndLast(struct node* head){
    struct node *temp=head;
    struct node *temp1=head;
    if(head==NULL)
        printf("There isnt any data.");
    else{
        while(temp->next->next!=NULL)
            temp=temp->next;
        temp->next->next=temp1->next;
        head=temp->next;
        temp->next=temp1;
        temp1->next=NULL;
    }
    return head;
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

void printLIST(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->number);
        temp=temp->next;
    }
}

int main(){
    struct node *head=NULL;
    head=addbegin(head,1);
    head=addbegin(head,2);
    head=addbegin(head,3);
    head=addbegin(head,4);
    head=addbegin(head,5);
    head=addbegin(head,6);
    head=addbegin(head,7);
    head=changeFirstAndLast(head);
    printLIST(head);
    return 0;
}
