#include<stdio.h>

int main(){
	int n,i,n1,ilk,son,orta,aranan;
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
	
	ilk=0;
	son=n-1;
	orta=(ilk+son)/2;
	while(ilk<=son)
	{
		if(dizi[orta]<aranan)
		{
			ilk=orta+1;
		}
		else if(dizi[orta]==aranan)
		{
			printf("%d sayisi %d. sirada bulundu.",aranan,orta+1);
		}
		else
		{
			son=orta-1;
			
		}
		orta=(ilk+son)/2;
	}
	if(ilk>son)
	{
		printf("%d sayisi bulunamad�.",aranan);
	}
	return 0;
	getch();
}
