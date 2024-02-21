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

void printLIST(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->number);
        temp=temp->next;
    }
}

struct node *deleteMiddle(struct node *head){
    struct node *temp=head;
    int n=0;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    n/=2;
    temp=head;
    n--;
    for(int i=1;i<n;i++)
        temp=temp->next;
    struct node *deleted=NULL;
    deleted=temp->next;
    temp->next=temp->next->next;
    free(deleted);
    return head;
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
    head=deleteMiddle(head);
    printLIST(head);
    return 0;
}
