#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *file,*file1;
	char c;
	file=fopen("udemy.txt","r");
	file1=fopen("udemy201birlestirme.txt","a");
	
	while(!feof(file))
	{
		c=fgetc(file);
		fputc(c,file1);
		//fprintf(file1,"%s",c);
	}
	fclose(file);
	fprintf(file1,"\n");
	file=fopen("lab13.dat","r");
	while(!feof(file))
	{
		c=fgetc(file);
		fputc(c,file1);
		//fprintf(file1,"%s",c);
	}
	fclose(file1);
	
	return 0;
}
