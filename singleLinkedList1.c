#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *addfront(struct node *head,int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
}

struct node *addend(struct node *head, int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else{
		struct node*last=head;
		while(last->next!=NULL)
			last=last->next;
		last->next=temp;
		last=head;
	}
	return head;	
}

int count (struct node *head){
	int counter=0;
	while(head!=NULL){
		counter++;
		head=head->next;
	}
	return counter;
}

int countRecursively (struct node *head){
	if(head==NULL)
		return 0;
	else
	return 1+countRecursively(head->next);
	
}

void printReverseOrderRecursively(struct node *head){
	if(head==NULL)	
		return;
//	printf("%4d",head->data); // if we want to write normal order
	printReverseOrderRecursively(head->next);
	printf("%4d",head->data); // if we want to write reverse order

}

void print(struct node *head){
	if(head==NULL)
		printf("\nList is empty.\n");
	else{
		printf("\n");
		while(head!=NULL){
			printf("%4d",head->data);
			head=head->next;
		}
		printf("\n");
	}
}

struct node *delete(struct node *head,int x){
	if(head==NULL){
		printf("List is empty.");
		return NULL;
	}
		struct node *temp=head;
		if(head->data==x){
			head=head->next;
			free(temp);
		}else{
			while(temp->next!=NULL&&temp->next->data!=x)
				temp=temp->next;
			if(temp->next==NULL)
				return head;
			struct node *deleted=temp->next;
			temp->next=deleted->next;
			free(deleted);
		}
	
	return head;
}

struct node *destroy(struct node *head){
	struct node *temp=head;
	while(head!=NULL){
		head=head->next;
		free(temp);
		temp=head;
	}
}

int main(){
	int number;
	struct node *head=NULL;
	
	int choice;
	while(1){
		printf("\n0:exit\n1:addfront\n2:addend\n3:Count how many number there is in a list\n4:Count how many number there is in a list with Recursively\n5:Print Reverse Order Recursively\n6:print the list\n7:delete a number in the list\nEnter a number: ");
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
			printf("\nThere is/are %d number(s) in the list.\n",count(head));
			break;
			
		case 4:
			printf("\nThere is/are %d number(s) in the list.\n",countRecursively(head));
			break;
			
		case 5:
			printReverseOrderRecursively(head);
			break;
			
		case 6:
			print(head);
			break;
			
		case 7:
			printf("Enter a number for delete in the list: ");
			scanf("%d",&number);
			head=delete(head,number);
			print(head);
			break;
			
		case 8:
			head=destroy(head);
			break;
			
		default: printf("\nPlease only enter from number 1 to 7:\n");
		}
	}
	return 0;	
}

