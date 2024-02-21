#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct studentFile{
    int sn;
    char ns[50];
    char department[50];
};

struct studentList{
    int sn;
    char ns[50];
    char department[50];
    struct node *next;
};
typedef struct studentList stdl;
typedef struct studentFile stdf;

stdl* readfromfilewritetolist(stdl *head,FILE *file){
    stdf std={0,"",""};
    while(!feof(file)){
        stdl *newnode=malloc(sizeof(std));
        fread(&std,sizeof(std),1,file);
        newnode->sn=std.sn;
        strcpy(newnode->ns,std.ns);
        strcpy(newnode->department,std.department);
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else{
            stdl *temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }
    return head;
}

void printList(stdl *head){
    stdl *temp=head;
    printf("\n%-20s%-30s%-50s\n","Student Number","Name and Surname", "Department");
    while(temp!=NULL){
        printf("%-20d%-30s%-50s\n",temp->sn,temp->ns,temp->department);
        temp=temp->next;
    }
}

int main(){
    stdl *head=NULL;
    FILE *file=fopen("lab13-1.dat","r");
    if(file==NULL){
        printf("\n!!! The file couldnt be open !!!\n");
        return;
    }
    else{
        head=readfromfilewritetolist(head,file);
        printList(head);
        fclose(file);
    }
    return 0;
}
