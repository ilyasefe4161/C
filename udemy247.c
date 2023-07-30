#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *file0, *file1, *file2;
	char c;
	file0=fopen("udemy247.dat","w");
	file1=fopen("udemy.txt","r");
	file2=fopen("udemy244.dat","r");
	while(!feof(file1))
	{
		c=getc(file1);
		putc(c,file0);
	}
	fprintf(file0,"\n");
	while(!feof(file2))
	{
		c=getc(file2);
		putc(c,file0);
	}
	fclose(file0);
	fclose(file1);
	fclose(file2);
	return 0;
}
