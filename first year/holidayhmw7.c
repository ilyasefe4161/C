#include<stdio.h>
#include<stdlib.h>

struct node{
	int age;
	struct head *next;
};
struct node *head=NULL;
struct node *tail=NULL;

int add(int age){
	if(head==NULL){
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->age=age;
		new->next=NULL;
		head=tail=new;
		}
	else{
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->age=age;
		new->next=NULL;
		tail->next=new;
		tail=new;
	}
	return 0;
}

int print(){
	printf("Linked List: ");
    
	struct node *index = head;
    
	while(index!=NULL){
        printf("%d - ", index->age);
        index = index->next;
    }
    printf("\n");
    return 0;
}

struct node* deleteNode(int n)
{
    struct node *temp = head;     
	struct node *temp1 = NULL;   
    int i;
    for(i=0;i<n-1;i++)
    {
    	temp1=temp;
		temp=temp->next;
    }
    struct node *del = temp;
    temp1->next=temp->next;
    free(del);
	return 0;
}

int main(){
add(1);
add(2);
add(3);
add(4);
add(5);
add(6);
add(7);
deleteNode(5);
print();
return 0;	
}
