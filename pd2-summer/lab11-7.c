#include<stdio.h>
#include<stdlib.h>

struct node{
    int age;
    struct node *next;
};

struct node* addbegin(struct node *head, int num){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->age=num;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;
}

struct node *deleteNode(struct node *head, int age){
    struct node *current=head;
    struct node *previous=NULL;
    int counter=0;

    if (head == NULL || head->next == NULL) {
            printf("there isnt enough node.");
        return head;
    }
    while (current != NULL) {
        if (current->age == age) {
            counter++;
            if (counter == 2) {
                if (previous == NULL) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                break;
            }
        }
        previous = current;
        current = current->next;
    }
    return head;
}

void printList(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->age);
        temp=temp->next;
    }
}

int main(){
    struct node *head=NULL;
    head=addbegin(head,21);
    head=addbegin(head,22);
    head=addbegin(head,21);
    head=addbegin(head,23);
    head=addbegin(head,29);
    head=addbegin(head,72);
    head=addbegin(head,21);
    printf("Before deleted: ");
    printList(head);
    head=deleteNode(head,21);
    printf("\nAfter deleted: ");
    printList(head);
    return 0;
}
