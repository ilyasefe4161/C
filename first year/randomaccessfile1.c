#include<stdio.h>
struct data{
	int no;
	char names[50];
	int balance;
};
typedef struct data customer;

customer empyt = {0,"",0};

void openfile(FILE *file){
	int i;
	file=fopen("randomaccessfile1.dat","r+");
	printf("enter a number from 1 to 10:\n ");
	scanf("%d",&empyt.no);
	while(empyt.no!=0)
	{
		printf("enter your name:\n ");
		getchar();
		gets(empyt.names);
		printf("enter your balance:\n ");
		scanf("%d",&empyt.balance);
		fseek(file,(empyt.no-1)*sizeof(customer),SEEK_SET);
		fwrite(&empyt,sizeof(customer),1,file);
		printf("enter a number, for finish enter 0(zero):\n ");
		scanf("%d",&empyt.no);
	}
	
	fclose(file);
}

void readfile(FILE *file){
	int i;
	file=fopen("randomaccessfile1.dat","r");
	printf("CUSTOMER NO:\tCUSTOMER NAME:\tCUSTOMER BALANCE:\n");
	while(!feof(file))
	{	
		fread(&empyt,sizeof(customer),1,file);
		if(empyt.no!=0)
			printf("%d\t%s\t\t\t\t%d\n",empyt.no,empyt.names,empyt.balance);
	}
	
	fclose(file);
}

int main(){
	int i;
	FILE *file;
	//file=fopen("randomaccessfile1.dat","w");
	fprintf(file,"%-10s%16s%16s\n","no", "namesurname", "balance");
		for(i=0;i<100;i++)
		{
			fwrite(&empyt,sizeof(customer),1,file);
		}
	printf("DONE.\n");
	fclose(file);
	
	openfile(file);
	readfile(file);
	
	return 0;
}
