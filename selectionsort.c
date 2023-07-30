#include<stdio.h>

int main(){
	int n,i,temp,j,konum;
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
	
	for(i=0;i<n;i++){
		printf("%d\t",dizi[i]);
	}
	
	for(i=0; i<n-1; i++){
		konum=i;
		for(j=i+1; j<n; j++){
			if(dizi[konum]>dizi[j])
			konum=j;
		}
		if(konum!=i){
		temp=dizi[konum];
		dizi[konum]=dizi[i];
		dizi[i]=temp;
	}
	}
	
	printf("After the sorting, Numbers: ");
	
	for(i=0;i<n;i++){
	printf("%d\t",dizi[i]);
}
	
	return 0;
}
