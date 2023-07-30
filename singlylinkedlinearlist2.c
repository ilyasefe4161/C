#include<stdio.h>
#include<stdlib.h>

struct data{
	int age;
	struct data *next;
};
typedef struct data node;
node *head=NULL,*tail=NULL;

void addend(int age)
{
	if(head==NULL)
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->age=age;
		newnode->next=NULL;
		head=tail=newnode;
	}
	else
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->age=age;
		newnode->next=NULL;
		tail->next=newnode;
		tail=newnode;	
	}
}

void addhead(int age)
{
	if(head==NULL)
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->age=age;
		newnode->next=NULL;
		tail=head=newnode;
	}
	else
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->age=age;
		newnode->next=head;
		head=newnode;
	}
}

node* delete1(int x)
{
    node* temp;
    temp=head;
    node* prev = NULL;
    if (temp->age == x)
    {
        head = temp->next;
        free(temp);            
        return;
    }
      else
    {
    while (temp != NULL && temp->age != x)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
    	printf("number of %d didnt find for delete.\n",x);
        return;
 	}
    prev->next = temp->next;
    free(temp);
    }
}

void print(){
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->age);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	addend(5);
	addend(2);
	addend(3);
	addhead(53);
	addhead(54);
	addhead(23);
	print();
	
	delete1(7);
	delete1(23);
	delete1(9);
	print();
	return 0;
}
