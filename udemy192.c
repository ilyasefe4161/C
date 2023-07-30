#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i;
	char character,sentence[20];
	FILE *file;
	
	file=fopen("udemytxt","w");
	
	printf("Write a sentence: ");
	gets(sentence);
	
	printf("How many times do you want to write a sentence?\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		//printf("ok\n");
		fprintf(file,"%s\n",sentence);
	}
	fclose(file);
	
	file=fopen("udemy.txt","r");
	if(file==NULL)
	{
		printf("cant open");
	}

	character=getc(file);
	while(character!=EOF)
	{
		printf("%c",character);
		character=getc(file);
	}
	
	fclose(file);
	
	return 0;
}
