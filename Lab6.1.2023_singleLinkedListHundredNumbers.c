#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node list{
	int data;
	struct node *next;
};

struct node addfront(struct node *head, int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
}

struct node addend(struct node *head, int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else{
		struct node *last;
		while(last->next!=NULL)
			temp=temp->next;
		last->next=temp;
		last=temp;
	}
	return head;
}

void bubble_sort() {
	
}

void print(){
	
}

int main(){
	srand(time(NULL));
	rn=rand()%0+100;
	print();
	bubble_sort();
	print();
}
