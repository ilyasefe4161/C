#include<stdio.h>
#include<stdio.h>
#define STACK_SIZE 10

typedef struct{
	char data[STACK_SIZE];
	int top;
}stack;
void initialize(stack *stk){
	stk->data[STACK_SIZE]=-1;
}
void push(stack *stk, char x){
	if(stk->top==STACK_SIZE-1)
		printf("\nstack is full.");
	stk->data[++stk->top]=x;
}
int pop(stack *stk){
	if(stk->top==-1){
		printf("\nstack is empty.");
		return;
	}
	return stk->data[stk->top--];
}

int main(){
	stack s;
	initialize(&s);
	
	return 0;
}
