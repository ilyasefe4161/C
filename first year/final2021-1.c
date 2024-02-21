#include<stdio.h>
#include<stdlib.h>

int main(){
	int *odd,*even,st=2010213027,n,i=0,k=0,l;
	even=(int*)malloc(sizeof(int));
	odd=(int*)malloc(sizeof(int));

		while(st!=0)
		{
			n=st%10;
			st=st/10;
		
			if(n%2==0)
			{
				even=(int*)realloc(even,sizeof(int));
				*(even+i)=n;
				i++;
			}
			else
			{
				odd=(int*)realloc(odd,sizeof(int));
				*(odd+k)=n;
				k++;
			}
		}
	printf("EVEN: \n");
	for(l=0;l<i;l++)
	{
		printf("%d\n",*(even+l));
	}
	printf("ODD: \n");
	for(l=0;l<k;l++)
	{
		printf("%d\n",*(odd+l));
	}
	free(even);
	free(odd);
	return 0;
}
