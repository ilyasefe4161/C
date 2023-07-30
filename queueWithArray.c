#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5

typedef struct{
	int counter;
	struct node *front;
	struct node *rear;
	int data[STACK_SIZE]
}queue;


