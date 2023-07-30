#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *previous;
};

struct node *addfront(struct node *head,int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->next=head;
	temp->previous=NULL;
	temp->data=x;
	if(head!=NULL)
		head->previous=temp;
	head=temp;
	return head;
}

struct node *addend(struct node *head,int x){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		temp->previous=NULL;
		head=temp;
	}else{
		struct node *last=head;
		while(last->next!=NULL)
		last=last->next;
	last->next=temp;
	temp->previous=last;
	}
	return head;
}

struct node *delete(struct node *head, int x){
		if(head==NULL){
		printf("List is empty.");
		return 0;
	}
	struct node *temp=head;
		if(head->data==x){
			head=head->next;
			free(temp);
			head->previous=NULL;
		}else{
			while(temp!=NULL&&temp->data!=x)
				temp=temp->next;
				if(temp==NULL)
					return head;		
				temp->previous->next=temp->next;
				if(temp->next!=NULL)
				temp->next->previous=temp->previous;
//				free(temp);
		}	
	return head;
}

void print(struct node *head){
	if(head==NULL)
		printf("\nList is empty.");
	else{
		printf("\n");
			while(head!=NULL){
			printf("%4d",head->data);
			head=head->next;	
		}
	}
	printf("\n");
}

int main(){
	struct node *head=NULL;
	struct node *previous=NULL;
	int choice,number;
	
	while(1){
	printf("\n0:exit\n1:addfront\n2:addend\n3:delete\n4:print\nEnter a choice: ");
	scanf("%d",&choice);
	switch(choice){
		
		case 0: exit(0);
		
		case 1:
			printf("Enter a number for addfront the list: ");
			scanf("%d",&number);
			head=addfront(head,number);
			break;
		
		case 2:
			printf("Enter a number for addend the list: ");
			scanf("%d",&number);
			head=addend(head,number);
			break;
			
		case 3:
			printf("Enter a number for addfront the list: ");
			scanf("%d",&number);
			head=delete(head,number);
			print(head);
			break;
			
		case 4:
			print(head);
			break;
		
		default: printf("\nPlease only enter from number 0 to 4:\n");
	}
}
	return 0;
}
