#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_SIZE 50
#define QUEUE_SIZE 50

struct node{
	int data;
	struct node *next;
};

typedef struct{
	int counter_q;
	struct node *front;
	struct node *rear;
}queue;

int isEmpty(queue *q){
	if(q->counter_q==0)
		return 1;
	else
		return 0;
}

int isFull(queue *q){
	if(q->counter_q==QUEUE_SIZE)
		return 1;
	else
		return 0;
}

void initialize_q(queue *q){
	q->counter_q=0;
	q->front=q->rear=NULL;
}

void enqueue(queue *q, char c){
	if(isFull(q))
		printf("queue is full.\n");
	else{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=c;
		temp->next=NULL;
		if(isEmpty(q))
			q->front=q->rear=temp;
		else{
			q->rear->next=temp
			q->rear=temp;
			}
		q->counter_q++;
		}
}

int dequeue(queue *q){
	if(isEmpty)
		printf("queue is empty.\n");
	else{
		struct node *temp=q->front;
		char x=temp->data;
		q->front=temp->next;
		free(temp);
		q->counter_q--;
		return x;
	}
}

typedef struct{
	int counter_s;
	struct node *top;
}stack;

void initialize_s(stack *s){
	s->counter_s=0;
	s->top=NULL;
}

void push(stack *s, char c){
	if(s->counter_s==STACK_SIZE)
		printf("stack is full.\n");
	else{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=c;
		temp->next=s->top;
		s->top=temp;
		s->counter_s++;
	}
}

int pop(stack *s){
	if(s->counter_s==0)
		printf("stack is empty\n");
	else{
		struct node *temp=s->top;
		char x=temp->data;
		s->top=temp->next;
		free(temp);
		s->counter_s--;
		return x;
	}
}

int main(){
	stack s;
	queue q;
	initialize_s(&s);
	initialize_q(&q);
	
}
