#include<stdio.h>
#include<stdlib.h>

struct data{
	int x;
	struct node *next;
};
typedef struct data node;
node *tail=NULL, *head=NULL;

void addend(int x){
	if(head==NULL)
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=NULL;
		tail=head=newnode;
	}
	else
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=NULL;
		tail->next=newnode;
		tail=newnode;
	}
}

void addhead(int x){
	if(head==NULL)
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=NULL;
		tail=head=newnode;
	}
	else
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=head;
		head=newnode;
	}
}

node* deletee(int x){
	node *temp,*prev;
	temp=head;
	if(temp->x==x)
	{
		head=temp->next;
		free(temp);
	}
	else
	while(temp->next!=NULL && temp->x!=x)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp->x==x)
	{
		prev->next=temp->next;
		free(temp);
	}
	else if(temp->next==NULL)
	{
		printf("\nwe can not find %d.",x);
	
	}
}
void print(){
	node *temp;
	temp=head;
	printf("\nLIST: ");
	while(temp!=NULL)
	{
		printf("\t%d",temp->x);
		temp=temp->next;
	}
	
}
int main(){
	addhead(1);
	addhead(2);
	addhead(3);
	addhead(4);
	addhead(5);
	addend(11);
	addend(22);
	addend(33);
	addend(44);
	addend(55);
	print();
	deletee(1);
	deletee(3);
	deletee(33);
	deletee(55);
	deletee(9);
	print();
	return 0;
}
