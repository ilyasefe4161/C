#include<stdio.h>

int main(){
	char c[50]="alperen   sarisuleyman ";
	FILE *f;
	f=fopen("udemy248.txt","w");
	fwrite(c,1,50,f);
	fseek(f,0,SEEK_SET);
	//fwrite("ilyas efe",1,9,f);
	fputs("ilyas efe",f);
	fread(c,1,20,f);
	fclose(f);
	return 0;
}
