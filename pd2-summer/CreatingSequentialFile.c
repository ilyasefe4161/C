#include<stdio.h>
#include<stdlib.h>

int main(){
    char name[20];
    char surname[20];
    int sn;
    int midgrade;
    int fingrade;
    int n;
    FILE *file;
    file=fopen("sequentialFile.txt","a+");
    if(file==NULL)
        printf("File couldnt open.");
    while(n!=0){
        printf("enter your name, surname, student number, midgrade, fingrade:\n");
        scanf("%s %s %d %d %d",name, surname, &sn, &midgrade,&fingrade);
        fprintf(file,"%s %s %d %d %d\n",name,surname,sn,midgrade,fingrade);
        printf("for EXIT enter 0(zero)\nAdding informations to database:\n");
        scanf("%d",&n);
    }
    fclose(file);
    return 0;
}
