#include<stdio.h>
#include<stdlib.h>
int main(){
	int i;
	FILE *file;
	char files[100],c;
	
	print("Enter the name and extension of the file: ");
	scanf("%s",files);
	
	file=fopen("files","r");
	
	while(!feof(file))
	{
		c=getc(file);
		printf("%c",c);
		
	}
	fclose(file);
	return 0;
}
