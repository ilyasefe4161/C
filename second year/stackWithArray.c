#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 3

typedef struct{
	int data[STACK_SIZE];
	int top;
}stack;

//Initialization or Reseting
void Reset(stack *stk){
	stk->top=-1;
}

//Push Operator
int push(stack *stk,int c){
	if(stk->top==STACK_SIZE-1)
		printf("\nStack is full.");
	else{
//		stk->top++;
//		stk->data[stk->top]=c;
		stk->data[++stk->top]=c;
	}
}

//POP Operator
int pop(stack *stk){
	if(stk->top==-1){
		printf("\nStack is empty.");
		return -100;
	}
	else{
//		int x=stk->data[stk->data];
//		stk->top--;
//		return x;
		return stk->data[stk->top--];
	}
}

int main(){
stack s;
	Reset(&s);
	FILE *file;
	char c;
	if((file=fopen("C:\\Users\\ilyasefe\\Desktop\\IES\\C\\test.txt","r"))==NULL){
		printf("\nthere is no file.");
		return 0;
	}
	else{
	while(!feof(file)){
		c=getc(file);
		switch(c){
			case '(':
				push(&s,c);
				break;
				
			case ')':
				if(pop(&s)=='(')
					continue;
				else{
					printf("\nthere is a problem for ().");
					exit(1);
				}
				break;
				
			case '{':
				push(&s,c);
				break;
				
			case '}':
				if(pop(&s)=='{')
					continue;
				else{
					printf("\nthere is a problem for {}.");
					exit(1);
				}
				break;		
					
			case '[':
				push(&s,c);
				break;
				
			case ']':
				if(pop(&s)=='[')
					continue;
				else{
					printf("\nthere is a problem for [].");
					exit(1);
				}
				break;
				
			default: printf("\nthere is a problem."); break;
		}
	}
	if(s.top==-1)
		printf("\nthere isnt error.");
	else
		printf("\nthere is a error which is as leasat one openin bracet not closed.");
	}
	fclose(file);
	return 0;
}
