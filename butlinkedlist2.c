#include<stdio.h>
#include<stdlib.h>

struct data{
	int x;
	struct node *next;
};
typedef struct data node;
node *tail=NULL, *head=NULL;

void addend(int x){
	node *newnode=(node*)malloc(sizeof(node));
	newnode->x=x;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=tail=newnode;
	}
	else
	{
		tail->next=newnode;
		tail=newnode;
	}
}
void addhead(int x){
	node *newnode=(node*)malloc(sizeof(node));
	newnode->x=x;
	if(head==NULL)
	{
		newnode->next=NULL;
		head=tail=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void print(){
	node *temp;
	temp=head;
	printf("MY LIST: ");
	while(temp!=NULL)
	{
		printf("\t%d",temp->x);
		temp=temp->next;
	}
}
int main(){
	addend(11);
	addend(12);
	addend(13);
	addend(14);
	addend(15);
	
	addhead(21);
	addhead(22);
	addhead(23);
	addhead(24);
	addhead(25);
	print();
	
	return 0;
}
