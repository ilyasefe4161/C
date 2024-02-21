#include<stdio.h>
#include<stdlib.h>

int main(){
	int i;
	FILE *file;
	char files[100],c;
	
	printf("Enter the name and extension of the file: ");
	scanf("%s",files);
	
	file=fopen(files,"r");
	
	c=getc(file);
	while(c!=EOF)
	{
		printf("%c",c);
		c=getc(file);
	}
	
	fclose(file);
	return 0;
}
