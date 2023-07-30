#include<stdio.h>

int main(){
	int n,i,n1;
	printf("How many number will you enter: ");
	scanf("%d",&n);
	srand(time(0));
	int dizi[n];
	for(i=0;i<n;i++)
	{
		/*printf("enter number: ");
		scanf("%d",&dizi[i]);*/
		dizi[i]=rand()%100;
	}
	printf("Numbers: ");
	
	for(i=0;i<n;i++)
	{
		printf("%d\t",dizi[i]);
	}
	printf("\nWhich numnber do you want to find or search?\n");
	scanf("%d",&n1);
	
	for(i=0; i<n; i++)
	{
		if(dizi[i]==n1)
		{
			printf("%d sayisi %d. sirada bulundu.\n",n1,i+1);
			break;
		}
	}
	
	if(i==n)
	printf("%d wasn't found.",n1);
	return 0;
}
