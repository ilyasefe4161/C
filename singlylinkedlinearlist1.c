#include<stdio.h>
#include<stdlib.h>
struct person{
	int studentnumber;
	struct person *next;
};
typedef struct person node;
struct person *newnode,*head=NULL,*tail=NULL;

void addsona(node* studentnumber)
{
		if(head==NULL)
		{
			newnode=(node*)malloc(sizeof(node));
			newnode->studentnumber=studentnumber;
			newnode->next=NULL;
			tail=head=newnode;
		}
		else
		{
			if(newnode->studentnumber < studentnumber)	//yeni eklenecek sayi, son eklenenden büyükse sona eklenir.
			{
				newnode=(node*)malloc(sizeof(node));
				newnode->studentnumber=studentnumber;
				newnode->next=NULL;
				tail->next=newnode;
				tail=newnode;
			}	
			else	//yeni eklenecek sayi, son eklenenden küçükse basa eklenir.
			{
				newnode=(node*)malloc(sizeof(node));
				newnode->studentnumber=studentnumber;
				newnode->next=head;
				head=newnode;
			}
		}
}

void print()
{
	printf("Linked List: ");
    node *index = head;
    while(index!=NULL){
        printf("%d - ", index->studentnumber);
        index = index->next;
    }
    printf("\n");
}

int main(){
	int n,i,sn;
	printf("How many students in the list?: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("what is your student number: ");
	scanf("%d",&sn);
	addsona(sn);
	}
	print();
	return 0;
}
