#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
	
	int n,i,temp,j;
	printf("how many number will you enter: ");
	scanf("%d",&n);
	srand(time(0));
	int dizi[n];
	for(i=0;i<n;i++){
		/*printf("enter number: ");
		scanf("%d",&dizi[i]);*/
		dizi[i]=rand()%100;
	}
	printf("Numbers: ");
	
	for(i=0;i<n;i++)
		printf("%d\t",dizi[i]);
	
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(dizi[j]>dizi[j+1])
			{
				temp=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=temp;
			}
		}
	}
	
	printf("After the sorting, Numbers: ");
	
	for(i=0;i<n;i++){
	printf("%d\t",dizi[i]);
}
	return 0;
}
