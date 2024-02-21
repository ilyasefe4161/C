#include<stdio.h>
#include<stdlib.h>

int main(){
	char filename[50], c;
	FILE *filenew, *fileold;
	printf("enter a file name and extension: ");
	scanf("%s",filename);	
	
	fileold=fopen(filename,"r");
	filenew=fopen("udemy244.dat","w");
	while(!feof(fileold))
	{
		c=fgetc(fileold);
		putc(c,filenew);
	}
	
	fclose(fileold);
	fclose(filenew);
	return 0;
}
