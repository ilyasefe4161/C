#include<stdio.h>
struct student{
	char name[20];
	char surname[20];
	int midterm,final;
	float average;
};

int main(){
	int n,i;
	printf("enter a number: ");
	scanf("%d",&n);
	FILE *file;
	file=fopen("udemy.txt","w");
	struct student data[n];
	for(i=0;i<n;i++)
	{
		printf("write your name: ");
		getchar();
		gets(data[i].name);
		printf("write your surname: ");
		gets(data[i].surname);
		printf("enter your midterm grade: ");
		scanf("%d",&data[i].midterm);
		printf("write your final grade: ");
		scanf("%d",&data[i].final);
	}
	
	for (i=0;i<n;i++)
	{
		data[i].average=(data[i].midterm*0.4+data[i].final*0.6);
	}
	
	for(i=0;i<n;i++)
	{
		fprintf(file,"%s",data[i].name);
		fprintf(file,"%20s",data[i].surname);
		fprintf(file,"%10d",data[i].midterm);
		fprintf(file,"%10d",data[i].final);
		fprintf(file,"%10.2f",data[i].average);
		fprintf(file,"\n");
	}
	
	return 0;
}
