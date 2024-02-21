#include<stdio.h>
#include<stdlib.h>

int main(){
    int sn;
    char ns[50];
    char deparment[100];
    int n,find;
    FILE *file;
    while(1){
        printf("\n0:Exit\n1:Create File\n2:Add Record\n3:Read Record\n");
        scanf("%d",&n);
        switch(n){
            case 0:
                exit(0);
            case 1:
                file=fopen("lab12-1.txt","w");
                if(file==NULL)
                    printf("the file couldnt be opened");
                break;
            case 2:
                printf("Enter your student number: ");
                scanf("%d",&sn);
                printf("Enter your name: ");
                gets(ns);
                gets(ns);
                printf("Enter your deparment: ");
                gets(deparment);
                printf("Information to be added:\nstudent number: %d\nname: %s\ndepartment: %s",sn,ns,deparment);
                fprintf(file,"%d %s %s\n",sn,ns,deparment);
                break;
            case 3:
                file=fopen("lab12-1.txt","r");
                if(file==NULL)
                    printf("the file couldnt be opened");
                //printf("enter student number which you want to read information: ");
                //scanf("%d",&find);
                printf("%-20s %-10s %-10s\n","student number","name","department");
                fscanf(file,"%d %s %s\n",&sn,ns,deparment);
                while(!feof(file)){
                    printf("%-20d %-10s %-10s\n",sn,ns,deparment);
                    fscanf(file,"%d %s %s\n",&sn,ns,deparment);
                }
                break;
        }
    }
    fclose(file);
    return 0;
}
