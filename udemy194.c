#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i;
	char c;
	printf("enter a number: ");
	scanf("%d",&n);
	FILE *file;
	file=fopen("udemy.txt","w");
	for(i=0;i<n;i++)
	{	
		if(i%2==0)
		{
			fprintf(file,"%d=even\n",i);
		}
		else
			fprintf(file,"%d=odd\n",i);
	}
	fclose(file);
	
	file=fopen("udemy.txt","r");
	c=getc(file);
	putchar(c);
	while(!feof(file))
	{
		c=getc(file);
		putchar(c);
	}
	fclose(file);
	return 0;
}
