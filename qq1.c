#include<stdio.h>
#include<stdlib.h>

struct list{
	int number;
	struct list *next;
};
typedef struct list node;
node *head=NULL;
node *tail=NULL;

void reverse(){
	node* current=head;
	node* prev=NULL;
	node* son=NULL;
	
	while(current!=NULL)
	{
		son=current->next;
		current->next=prev;
		prev=current;
		current=son;
	}
	head=prev;
}

void addend(int number)
{
	if(head==NULL)
	{
		node* newnode=(node*)malloc(sizeof(node));
		newnode->number=number;
		newnode->next=NULL;
		head=tail=newnode;
	}
	else
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->number=number;
		newnode->next=NULL;
		tail->next=newnode;
		tail=newnode;	
	}
}

void print(){
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->number);
		temp=temp->next;
	}
	printf("\n");
}
int  main(){
	addend(1);
	addend(2);
	addend(3);
	addend(4); printf("%d\n",head); print();
	reverse(); print();
	printf("%d\n",head); return 0;}
