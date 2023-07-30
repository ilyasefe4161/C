#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
	int number;
	float midterm;
	char name[40];
};

struct student temp1;
struct student temp2;
struct student data = {0,0,""};

void ekle(){
	
	FILE *f;
	f=fopen("final-q4.dat","r+");
	printf("enter a number, midterm and name: \n");
	scanf("%d%f%s",&data.number,&data.midterm,data.name);
	fseek(f,(data.number-1)*sizeof(struct student),SEEK_SET);
	fwrite(&data,sizeof(struct student),1,f);
	
	fclose(f);
}

void first(){
	
	int i;
	FILE *f;
	f=fopen("final-q4.dat","w");
	for(i=0;i<10;i++)
	{
		fwrite(&data,sizeof(struct student),1,f);	
	}
	fclose(f);
	
}

void changing(){
	int n1,n2;
	FILE *f;
	f=fopen("final-q4.dat","r+");
	printf("enter two numberfor changing: \n");
	scanf("%d%d",&n1,&n2);
	while(!feof(f))
	{
		fread(&data,sizeof(struct student),1,f);
		if(n1==data.number)
		{
			temp1.number=data.number;
			temp1.midterm=data.midterm;
			strcpy(temp1.name,data.name);
		}
		if(n2==data.number)
		{
			temp2.number=data.number;
			temp2.midterm=data.midterm;
			strcpy(temp2.name,data.name);
		}
	}
	
	fseek(f,(n1-1)*sizeof(struct student),SEEK_SET);
	fwrite(&temp2,sizeof(struct student),1,f);
	fseek(f,(n2-1)*sizeof(struct student),SEEK_SET);
	fwrite(&temp1,sizeof(struct student),1,f);
	fclose(f);
}

void print(){
	FILE *f;
	f=fopen("final-q4.dat","r");
	while(!feof(f))
	{
		fread(&data,sizeof(struct student),1,f);
		if(data.number!=0)
		{
			printf("%d\t%.2f\t%s\n",data.number,data.midterm,data.name);
		}
	}
	fclose(f);
}

int main(){

	int secim;
	while(1)
	{
		printf("\n0: exit\n1: dosya olusturma\n2: changing\n3: print\n4: ekle\n");
		scanf("%d",&secim);
		
		switch(secim){
			case 0: 
			exit(0);
			case 1: first(); break;
			case 2: changing(); break;
			case 3: print(); break;
			case 4: ekle(); break;	
	}
	
	}
}
