#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10

typedef struct{
	char data[STACK_SIZE];
	int top;
	
}stack;

void initialize(stack *stk){
	stk->top=-1;
}

void push(stack *stk, char x){
	if(stk->top==STACK_SIZE-1)
		printf("\nstack is full.");
//	stk->top++;
//	stk->data[stk->top]=data;
	stk->data[++stk->top]=x;
}

int pop(stack *stk){
	if(stk->top==-1){
		printf("\nstack is empty.");
		return 0;
	}
		//	int x= stk->data[stk->data];
//	stk->top--;
//	return x;
	return stk->data[stk->top--];
}

int main(){
	stack s;
	initialize(&s);
	FILE *file;
	char c;
	if((file=fopen("test.txt","r"))==NULL){
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
					printf("\nthere is a problem for ).");
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
					printf("\nthere is a problem for }.");
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
					printf("\nthere is a problem for ].");
					exit(1);
				}
				break;
				
			default:break;
		}
	}
	if(s.top==-1)
		printf("\nthere isnt error.");
	else
		printf("\nthere is a error which is as least one opening bracet not closed.");
	}
	fclose(file);
	return 0;
}
