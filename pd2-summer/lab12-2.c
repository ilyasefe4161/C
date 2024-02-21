#include<stdio.h>

struct student{
    int sn;
    char ns[50];
    char deparment[100];
};

int main(){
    int n,findSN;
    FILE *file;
    while(1){
        printf("\n0:exit\n1:Creating a file\n2:add record\n3:reading records\n4:update records\n");
        scanf("%d",&n);
        switch(n){
            case 0:exit(0);fclose(file);

            case 1:file=fopen("randomAccessFile.dat","w");
                if(file==0)
                    printf("the file couldnt be open.");
                break;

            case 2:file=fopen("randomAccessFile.dat","r+");
                if(file==0)
                    printf("the file couldnt be open.");

                struct student std={0,"",""};
                printf("enter student number:");
                scanf("%d",&std.sn);
                printf("enter name surname:");
                gets(std.ns);
                gets(std.ns);
                printf("enter department:");
                gets(std.deparment);
                fseek(file,0,SEEK_END);
                fwrite(&std,sizeof(struct student),1,file);
                rewind(file);
                break;

            case 3:file=fopen("randomAccessFile.dat","r");
                if(file==0)
                    printf("the file couldnt be open.");
                fseek(file,0*sizeof(struct student),SEEK_SET);
                    printf("\n%-25s%-25s%-25s\n","student number","name surname","deparment");
                while(!feof(file)){
                    fread(&std,sizeof(struct student),1,file);
                    printf("%-25d%-25s%-25s\n",std.sn,std.ns,std.deparment);
                    fread(&std,sizeof(struct student),1,file);
                }
                rewind(file);
                break;
            case 4:file=fopen("randomAccessFile.dat","r+");
                if(file==0)
                    printf("the file couldnt be open.");

                struct student newstd={0,"",""};

                printf("Which student do you want to update? Enter the student number which you want to update: ");
                scanf("%d",&findSN);
                fseek(file,0*sizeof(struct student),SEEK_SET);
                fread(&std,sizeof(struct student),1,file);
                while(std.sn!=findSN){
                    fread(&std,sizeof(struct student),1,file);
                }
                printf("\nfounded.\n");

                printf("enter update student number:");
                scanf("%d",&newstd.sn);
                printf("enter update name surname:");
                gets(newstd.ns);
                gets(newstd.ns);
                printf("enter update department:");
                gets(newstd.deparment);

                fseek(file, -sizeof(struct student), SEEK_CUR);
                fwrite(&newstd, sizeof(struct student), 1, file);
                rewind(file);
                break;
            default: printf("!!! enter from 0 to 4 !!!\n");
        }
    }
    return 0;
}
