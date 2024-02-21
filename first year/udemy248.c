#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *file0, *file1;
	char c;
	file0=fopen("udemy248.dat","w");
	file1=fopen("udemy.txt","r");
	c=getc(file1);
	while(!feof(file1))
	{
		if(c >= 'a' && c <= 'z')
		fprintf(file0,"%c",c-32);
		else
		fprintf(file0,"%c",c);
		
		c=getc(file1);
	}
	fclose(file0);
	fclose(file1);
	return 0;
}
