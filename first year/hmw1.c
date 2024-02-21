#include<stdio.h>
#include<stdlib.h>

struct data{
	int x;
	struct node *next;
};
typedef struct data node;
node *tail=NULL, *head=NULL;

void addeven(int x){
	if(head==NULL)
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=NULL;
		head=tail=newnode;
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
void addodd(int x){
	if(head==NULL)
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=NULL;
		head=tail=newnode;
	}
	else
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=head;
		head=newnode;
	}
}
void print(){
	node *temp;
	temp=head;
	printf("LIST: ");
	while(temp!=NULL)
	{
		printf("\t%d",temp->x);
		temp=temp->next;
	}
}
int main(){
	addeven(1);
	addeven(2);
	addeven(3);
	addeven(4);
	addeven(5);
	addeven(6);
	addodd(9);
	addodd(8);
	addodd(7);
	addodd(6);
	addodd(5);
	addodd(4);
	print();
}
// QUESTION 6
void addeven(int x){
	if(head==NULL)
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=NULL;
		head=tail=newnode;
	}
	else
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=head;
		head=newnode;
	}
}

void addodd(int x){
	if(head==NULL)
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->x=x;
		newnode->next=NULL;
		head=tail=newnode;
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
