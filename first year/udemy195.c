#include<stdio.h>

int main(){
	int n,i;
	char s[50];
	FILE *file;
	file=fopen("udemy.txt","a");
	printf("enter a number: ");
	scanf("%d",&n);
	printf("Write something: ");
	getchar();
	gets(s);
	fprintf(file,"%s\n",s);
	for(i=0;i<n-1;i++)
	{
	printf("Write something: ");
	//getchar();
	gets(s);
	fprintf(file,"%s\n",s);
	}
	fclose(file);
	
	return 0;
}
