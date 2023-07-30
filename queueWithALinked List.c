#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5

struct node{
	int data;
	struct node *next;
};

typedef struct{
	int counter;
	struct node *front;
	struct node *rear;
}queue;

void initialize(queue *q){
	q->front=q->rear=NULL;
	q->counter=0;
}

int isFull(queue *q){
	if(q->counter==STACK_SIZE)
		return 1;
	else
		return 0;
}

int isEmpty(queue *q){
	if(q->counter==0)
		return 0;
	else
		return 1;
}

void enqueue(queue *q, int x){
	if(isFull(q))
		printf("queue is full.\n");
	else{
		struct node *temp=(struct node*)malloc(sizeof(queue));
		temp->data=x;
		temp->next=NULL;
		if(isEmpty(q))
			q->front=q->rear=temp;
		else{
			q->rear->next=temp;
			q->rear=temp;
		}
		q->counter++;
	}
}

int dequeue(queue *q){
	if(isEmpty(q)){
		printf("queue is empty.\n");
		return;
	}else{
		struct node *temp=q->front;
		int x=temp->data;
		q->front=temp->next;
		free(temp);
		q->counter--;
		return x;
	}
}

//void print(queue *q)
//	{ 	 
//		struct node *p;
//  		for(p=q->front;   p!=NULL;  p=p->next)
//			printf("%d  ", p->data);
//		printf("\n");	
//	}

int main(){
	queue q;
	initialize(&q);
	enqueue(&q,5);
	enqueue(&q,1);
//	print(&q);
	printf("%d",dequeue(&q));
	return 0;
}
