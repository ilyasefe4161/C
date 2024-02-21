#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct std{
	int studentnumber;
	char namesurname[50];
	char department[50];
};

int main(){
	int numara,numara1,numara2;
	int n,i,sn;
	FILE *f;
	struct std empyt = {0,"",""};
	struct std empyt0 = {0,"",""};
	struct std temp2 = {0,"",""};
	struct std temp1 = {0,"",""};
	while(1){
		printf("\n0:Exit\n1:Kayit Ekleme\n2:Hesap Guncelleme\n3:Hesap Silme\n4:Tum Kayitlari Listele\n6:Bos Kayit\n7:Hesaplari Degistirme\n ");
		scanf("%d",&n);
		switch(n){
			
			case 0:
				exit(0);
			
			case 1:
				f=fopen("lab13.dat","r+");
				printf("enter a new student number(1-100): ");
				scanf("%d",&empyt.studentnumber);
				if(empyt.studentnumber<=100){
				printf("enter your name surname:\n ");
				getchar();
				gets(empyt.namesurname);
				printf("enter your department:\n ");
				gets(empyt.department);
				fseek(f,(empyt.studentnumber-1)*sizeof(struct std),SEEK_SET);
				fwrite(&empyt,sizeof(struct std),1,f);
				fclose(f);	
				}
				else
				printf("\n!!!please enter from 1 to 100!!!\n");
				
				break;
			
			case 2:
				f=fopen("lab13.dat","r+");
				printf("enter a new student number(1-100): ");
				scanf("%d",&empyt.studentnumber);
				printf("enter your name surname:\n ");
				getchar();
				gets(empyt.namesurname);
				printf("enter your department:\n ");
				gets(empyt.department);
				fseek(f,(empyt.studentnumber-1)*sizeof(struct std),SEEK_SET);
				fwrite(&empyt,sizeof(struct std),1,f);
				fclose(f);
				break;
			
			case 3:
				printf("enter a student number for delete(1-100): "); scanf("%d",&numara);
				f=fopen("lab13.dat","r+");
				
				fread(&empyt0,sizeof(struct std),1,f);
				
				fseek(f,(numara-1)*sizeof(struct std),SEEK_SET);
				fwrite(&empyt,sizeof(struct std),1,f);
				
				fclose(f);
				break;
			
			case 4:
				system("cls");
				f=fopen("lab13.dat","r");
				printf("%-16s%16s%16s\n","studentnumber","namesurname","department");
				while(!feof(f))
				{
					fread(&empyt,sizeof(struct std),1,f);
					if(empyt.studentnumber!=0)
						printf("%-16d%16s%16s\n",empyt.studentnumber, empyt.namesurname, empyt.department);
				}
				fclose(f);
				break;
			/*
			case 5:
				f=fopen("lab13.dat","r+");
				while(!feof(f))
				{
					fseek(f,(empyt.studentnumber-1)*sizeof(struct std),SEEK_SET);
					fread(&empyt,sizeof(struct std),1,f);
				
					fseek(f,(empyt.studentnumber-1)*sizeof(struct std),SEEK_SET);
					fwrite(&empyt0,sizeof(struct std),1,f);
				}
				fclose(f);
				break;
			*/
			case 6:
				f=fopen("lab13.dat","w");
				for(i=1;i<=100;i++)
				{
					fwrite(&empyt,sizeof(struct std),1,f);
				}
				fclose(f);
				break;
				
				case 7:
					f=fopen("lab13.dat","r+");
					printf("enter two student number for changing(1-100): "); scanf("%d%d",&numara1,&numara2);
					while(!feof(f))
					{
						fread(&empyt,sizeof(struct std),1,f);
						if(numara1==empyt.studentnumber)
						{
								temp1.studentnumber=empyt.studentnumber;
								strcpy(temp1.namesurname,empyt.namesurname);
								strcpy(temp1.department,empyt.department);
						}
						if(numara2==empyt.studentnumber)
						{
								temp2.studentnumber=empyt.studentnumber;
								strcpy(temp2.namesurname,empyt.namesurname);
								strcpy(temp2.department,empyt.department);
						}
					}
					fseek(f,(numara1-1)*sizeof(struct std),SEEK_SET);
					fwrite(&temp2,sizeof(struct std),1,f);
					
					fseek(f,(numara2-1)*sizeof(struct std),SEEK_SET);
					fwrite(&temp1,sizeof(struct std),1,f);
					fclose(f);
					break;
			default: 
				printf("\n!!!Please enter number from 1 to 7!!!\n\n");
			}
	}
return 0;
}
