#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 3

typedef struct{
	int counter;
	int data;
	struct node *top;
	struct node *next;
}stack;

//initialize
void initialize(stack *stk){
	stk->counter=0;
	stk->top=NULL;
}

//Push Operator
void push(stack *stk, int c){
	if(stk->counter==STACK_SIZE)
		printf("\nStack is full.");
	else{
		stack *temp=(stack*)malloc(sizeof(stack));
		temp->data=c;
		temp->next=stk->top;
		stk->top=temp;
		stk->counter++;
	}
}

//POP Operator
int POP(stack *stk){
	if(stk->counter==0){
		printf("\nStack is empty.");
		return -100;
	}
	else{
		stack *temp=stk->top;
		stk->top=temp->next;
		int x=temp->data;
		free(temp);
		stk->counter--;
		return x;
	}
}

int main(){
	int value[5]={7,9,11,13,15};
	stack s;
	initialize(&s);
	int i;
	for ( i=0;i<5;i++)
		push (&s,value[i]);
	int n=30;
	for ( i=0;i<3;i++)
		n+=pop(&s);
	for ( i=0;i<2;i++)
		n=pop(&s);
	printf("%d",n);
}
