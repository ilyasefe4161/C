#include<stdio.h>

void findmax(int dizi[],int x){
	int max,i;
	max=dizi[0];
	for(i=1;i<x;i++)
	{
		if(dizi[i]>max)
		max=dizi[i];
	}
	printf("\nmaximum number is: %d",max);
	
}

void  findmin(int dizi[],int x){
	int min,i;
	min=dizi[0];
	for(i=1;i<x;i++)
	{
		if(dizi[i]<min)
		min=dizi[i];
	}
	printf("\nminimum number is: %d",min);
}

int main(){
	int n[10],i;
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		n[i] = rand() % 10;
	}
	for(i=0;i<10;i++)
	{
		printf("%d\t",n[i]);
	}
	findmax(n,10);
	findmin(n,10);
	
	return 0;
}
