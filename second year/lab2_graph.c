#include <stdio.h>
#include <stdlib.h>
struct node {
    int vertex;
    int data;
    struct node* next;
};

struct node *head=NULL;

struct node *addedge(struct node *head, int x){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node *last = head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=temp;
    }
    return head;

}

int degree(int a[][5] , int v, int n){
    int result = 0, i;
    for ( i = 0; i < n; i++)
    {
        result += a[v][i];
    }
    return result;
}

void print(struct node *head){
    if(head==NULL){
        printf("The list is empty\n");
    }
    else{
        while (head!=NULL){
            printf("%d ",head->data);
            head=head->next;
        }
    }
    printf("\n");
}

int main(){
    struct node *head[5]={NULL};
    int i;
    for(i = 0;i<5;i++){
        head[i]=addedge(head[i],i+1);
    }
    addedge(head[0],2);
    addedge(head[1],3);
    addedge(head[1],5);
    addedge(head[2],5);
    addedge(head[2],4);
    addedge(head[3],5);
    addedge(head[4],1);
    addedge(head[4],4);
    for(i=0;i<5;i++){
        print(head[i]);
    }
}
