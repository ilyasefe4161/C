#include<stdio.h>
int main(){
	int no,n=1;
	float point;
	char name[50],c="ahmet";
	FILE *file;
	file=fopen("notlar.txt","a+");
	printf("enter a number: ");
	scanf("%d",&n);
	while(n!=0){
	printf("enter a no, name, point: ");
	scanf("%d%s%f",&no,name,&point);
	fprintf(file,"%-10d%10s%10.2f\n",no,name,point);
	printf("enter a number: ");
	scanf("%d",&n);
	}
	fclose(file);
	
	printf("%-10d%10s%10.2f\n",no,name,point);
	
	file=fopen("notlar.txt","r");
	fscanf(file,"%s",name);
	fscanf(file,"%f",&point);
	while(name==c && point >= 60)
	{
		printf("%d%s%f",no, name, point);
		fscanf(file,"%s",name);
		fscanf(file,"%f",&point);
	}
	fclose(file);
	return 0;
}
