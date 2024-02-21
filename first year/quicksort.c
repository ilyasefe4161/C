#include<stdio.h>

int quicksort(int *d, int ilk, int son){
	int pivot,i,j,temp;
	if(ilk<son){
	pivot=ilk;
	i=ilk;
	j=son;
		while(i<j)
		{
			while(d[i]<=d[pivot] && i<son)
			i++;
		
			while(d[j]>d[pivot])
			j--;
			if(i<j)
			{
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
			temp=d[pivot];
			d[pivot]=d[j];
			d[j]=temp;
		}
	quicksort(d,ilk,j-1);
	quicksort(d,j+1,son);
	
	}
}

int main(){
	int n,i;
	printf("how many number will you enter: ");
	scanf("%d",&n);
	srand(time(0));
	int dizi[n];
	for(i=0; i<n; i++){
		/*printf("enter number: ");
		scanf("%d",&dizi[i]);*/
		dizi[i]=rand()%100;
	}
	
	printf("Numbers: ");
	
	for(i=0;i<n;i++){
		printf("%d\t",dizi[i]);
	}
	
	quicksort(dizi,0,n-1);
	
	printf("After the sorting, Numbers: ");
	
	for(i=0;i<n;i++){
	printf("%d\t",dizi[i]);
}
	return 0;
}
