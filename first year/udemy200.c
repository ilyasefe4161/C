#include<stdio.h>
#include<stdlib.h>
int main(){
	int n=1;
	FILE *file;
	char c[100];
	file=fopen("udemy.txt","a");
	
	while(1)
	{
		printf("enter only a word: ");
		gets(c);
		if(c[0]=='0')
		{
			exit(0);
		}
		fprintf(file,"%s\n",c);
		
	}	
	fclose(file);
	return 0;
}
