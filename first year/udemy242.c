#include<stdio.h>
#include<stdlib.h>
#define PI 3.14
int main(){
	FILE *file;
	file=fopen("acilar.txt","w");
	int i;
	double sinus,cosinus;
	fprintf(file,"DERECE\tSIN\tCOS\n");
	fprintf(file,"======\t===\t===\n");
	for(i=0;i<=360;i++)
	{
		sinus=sin(i*PI/180);
		cosinus=cos(i*PI/180);
		fprintf(file,"%d\t%lf\t%lf\n",i,sinus,cosinus);
	}
	fclose(file);
	return 0;
}
