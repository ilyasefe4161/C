#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insertEnd(struct node *head, int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

struct node *insertBeg(struct node *head, int data) {
   struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head==NULL)
        newnode=head;
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;
}

struct node *insertPos(struct node *head, int data, int position) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    struct node *temp = head;
    if(position==1){
        newnode->next=head;
        head=newnode;
    }
    else{
        position--;
        while(position!=1){
            temp=temp->next;
            position--;
        }
    newnode->next=temp->next;
    temp->next=newnode;
    }
    return head;
}

void printNodes(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

struct node *deleteFirst(struct node *head){
    struct node *temp = head;
    if(head==NULL)
        printf("\nList already empty.");
    else{
        temp=head->next;
        free(head);
        head=temp;
    }
    return head;
};

struct node *deleteLast(struct node *head){
    struct node *temp = head;
    if(head==NULL)
        printf("\nList already empty.");
    else{
        while(temp->next->next!=NULL)
            temp=temp->next;
        struct node *last = temp;
        last=last->next;
        free(last);
        temp->next=NULL;
    }
    return head;
};

struct node *deletePos(struct node *head, int position) {
    struct node *temp = head;
    if(position==1){
        head=head->next;
        free(temp);
    }
    else{
        position--;
        while(position!=1){
            temp=temp->next;
            position--;
        }
    }
    temp->next=temp->next->next;
    temp=temp->next;
    return head;
}

struct node *deleteValue(struct node *head, int data) {
    struct node *temp = head;
    if(head->data==data){
        head=temp->next;
        free(temp);
    }
    else{
        while(temp->next != NULL && temp->next->data!=data){
            temp=temp->next;
        }
        struct node *del = temp->next;
        temp->next=temp->next->next;
        temp=temp->next;
        free(del);
    }
    return head;
}

struct node* deleteEntire(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        free(head);
        head=temp;
    }
    return head;
}

struct node* reverse(struct node* head){
    struct node* nextnode=NULL;
    struct node* prevnode=NULL;
    while(head!=NULL){
        nextnode=head->next;
        head->next=prevnode;
        prevnode=head;
        head=nextnode;
    }
    head=prevnode;
    return head;
}

int main() {
    struct node *head = NULL;
    head = insertEnd(head, 9);
    head = insertEnd(head, 15);
    head = insertEnd(head, 27);
    head = insertBeg(head, 32);
    head = insertBeg(head, 431);
    head = insertBeg(head, 452);
    head = insertPos(head, 54, 1);
    //head = deleteFirst(head);
    //head = deleteLast(head);
    //head = deletePos(head, 1);
    //head = deleteValue(head, 9);
    //head = deleteEntire(head);
    //head = reverse(head);

    printNodes(head);
    return 0;
}
