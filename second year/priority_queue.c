#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 15

struct priority_queue{
	int a[QUEUE_SIZE+1];
	int cnt;
};

typedef struct priority_queue pqueue;
void initialize(pqueue *p){
	p->cnt=0;
}

void insert(pqueue *p, int key){
	if(p->cnt==QUEUE_SIZE)
		printf("Queue is Full.");
	else{
		p->cnt++;
		p->a[p->cnt]=key;
		int iter=p->cnt;
		while(iter!=1 && p->a[iter] < p->a[iter/2]){
			int temp=p->a[iter];
			p->a[iter]=p->a[iter/2];
			p->a[iter/2]=temp;
			iter=iter/2;
		}
	}
}

void print(pqueue *p){
	if(p->cnt==0)
		printf("Queue is Empty.");
	else{
		int i;
		for(i=1;i<=p->cnt;i++)
			printf("%5d",p->a[i]);
	}
}

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int delete(pqueue *p){
	if(p->cnt==0){
		printf("queue is empty.");
		return -1;
	}
	else{
		int key=p->a[1];
		p->a[1]=p->a[p->cnt];
		p->cnt--;
		int iter=1;
		while(2*iter <= p->cnt && (p->a[iter] > p->a[2*iter] || p->a[iter] > p->a[2*iter+1])){
			if(p->a[2*iter] < p->a[2*iter+1]){
				swap(&p->a[iter], &p->a[2*iter]);
				iter=2*iter;
			}
			else{
				swap(&p->a[iter], &p->a[2*iter+1]);
				iter=2*iter+1;
			}
		}
		return key;
	}
}

int main(){
	pqueue pq;
	initialize(&pq);
	insert(&pq,21);
	insert(&pq,4);
	insert(&pq,65);
	insert(&pq,9);
	insert(&pq,1);
	print(&pq);
	
	printf("\n");
	delete(&pq);
	print(&pq);
	
	return 0;
}
