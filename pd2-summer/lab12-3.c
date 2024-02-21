#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int sn;
    char ns[50];
    char deparment[100];
    struct student *next;
};

struct student *fromFileToLinkedList(struct student *head,FILE *file){
    fseek(file,0*sizeof(struct student),SEEK_SET);
    struct student *newnode=malloc(sizeof(struct student));
    struct student fileInfo;
    fread(&fileInfo,sizeof(struct student),1,file);
    while(!feof(file)){
        newnode->sn=fileInfo.sn;
        strcpy(newnode->ns,fileInfo.ns);
        strcpy(newnode->deparment,fileInfo.deparment);
        fread(&fileInfo,sizeof(struct student),1,file);
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else{
            struct student *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    rewind(file);
    return head;
}

void printList(struct student *head){
    struct student *temp=head;
    printf("\n%-25s%-25s%-25s\n", "student number", "name surname", "department");
    while(temp!=NULL){
        printf("%-25d%-25s%-25s\n",temp->sn,temp->ns,temp->deparment);
        temp=temp->next;
    }
}

int main(){
    FILE *file;
    struct student *head=NULL;
    file=fopen("randomAccessFile.dat","r");
    if(file==0)
        printf("the file couldnt not be open");
    head=fromFileToLinkedList(head,file);
    fclose(file);
    printList(head);
    return 0;
}
