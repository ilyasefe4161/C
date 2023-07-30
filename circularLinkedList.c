#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *addfront(struct node *head,int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL){
		temp->next=temp;
		head=temp;
	}		
	else{
		temp->next=head;
		struct node *last=head;
		while(last->next!=head)
			last=last->next;
		last->next=temp;
		head=temp;
	}
	return head;
}

struct node *addend(struct node *head,int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL){
		temp->next=temp;
		head=temp;
	}else{
		temp->next=head;
		struct node *last=head;
		while(last->next!=head)
			last=last->next;
		last->next=temp;
	}
	return head;
}

struct node *destroyRecursively(struct node *head){
	if(head==NULL)
		return NULL;
	destroyRecursively(head->next);
	free(head);
}

void print(struct node *head){
	if(head==NULL)
		printf("\nList is empty.\n");
	else{
		printf("\n");
		struct node *last=head->next;
		while(last!=head){
			printf("%4d",last->data);
			last=last->next;
		}
		printf("\n");
	}
}

int main(){
		struct node *head=NULL;
	int number,choice;
	while(1){
	printf("0:exit\n1:Addfront a number\n2:Addend a number\n3:Destroy recursively the list\n4: print \nEnter a choice: ");
	scanf("%d",&choice);
	switch(choice){
		
		case 0: exit(0);
		
		case 1:
			printf("Enter a number for addfront the list: ");
			scanf("%d",&number);
			head=addfront(head,number);
			break;
		case 2:
			printf("Enter a number for addfront the list: ");
			scanf("%d",&number);
			head=addend(head,number);
			break;
		
		case 3:
			destroyRecursively(head);
			print(head);
			break;
		case 4:
			print(head);
			break;
			
		default: printf("\nPlease only enter from number 0 to 3:\n");
}
}
	return 0;
}
