#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,n;
	char sentences[50];
	FILE *file;
	file=fopen("udemy.txt","w");
	printf("How many line do you want to write something? ");
	scanf("%d",&n);
	
	printf("Write a something: ");
	getchar();
	gets(sentences);
	fprintf(file,"%s\n",sentences);
		
	for(i=0;i<n-1;i++)
	{
		printf("Write a something: ");
		gets(sentences);
		fprintf(file,"%s\n",sentences);
	}
	fclose(file);
		
	file=fopen("udemy.txt","r");
	
	fgets(sentences,50,file);
	printf("%s",sentences);
	while(!feof(file))
	{
		fgets(sentences,50,file);
		printf("%s",sentences);
		fgets(sentences,50,file);
	}
	fclose(file);
	
	
	return 0;
}
