#include<stdio.h>
#include<stdlib.h>

struct student{
    int sn;
    char ns[50];
    int midgrade;
    int fingrade;
    struct node *link;
};
typedef struct student std;
std *stds;

std *Addnewrecord(std *head, int sn, char ns[], int midgrade, int fingrade){
    std *newnode = malloc(sizeof(std));

    newnode->sn=sn;
    strcpy(newnode->ns,ns);
    newnode->midgrade=midgrade;
    newnode->fingrade=fingrade;
    newnode->link=NULL;

    if(head==NULL)
        head=newnode;
    else{
        std *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
    }
    return head;
}

std Printlist(std *head){
    std *temp = head;
    while (temp != NULL) {
        printf("\nStudent number:%d", temp->sn);
        printf("\nStudent name:%s", temp->ns);
        printf("\nStudent midgrade:%d", temp->midgrade);
        printf("\nStudent fingrade:%d\n", temp->fingrade);
        temp = temp->link;
    }
}

std *Updaterecord(std *head, int find, int sn, char ns[], int midgrade, int fingrade){
    if(head->sn==find){
        head->sn=sn;
        strcpy(head->ns,ns);
        head->midgrade=midgrade;
        head->fingrade=fingrade;
    }
    else{
        std *temp=head;
        while(temp!=NULL && temp->sn!=find){
            temp = temp->link;
        }
        if(temp->link!=NULL)
            printf("couldnt find.");
        else{
            temp->sn=sn;
            strcpy(temp->ns,ns);
            temp->midgrade=midgrade;
            temp->fingrade=fingrade;
        }
    }
}

void calculateclassaverage(std *head){
    std *temp=head;
    int midaverage=0,finaverage=0,student=0,midsum=0,finsum=0;
    while(temp!=NULL){
        midsum+=temp->midgrade;
        finsum+=temp->fingrade;
        student++;
        temp=temp->link;
    }
    midaverage=midsum/student;
    finaverage=finsum/student;
    printf("midterm average: %d\nfinal average: %d\n",midaverage,finaverage);
}

void Printtopstudentbyaverage(std *head){

}

int main(){
    int sn,find;
    char ns[50];
    int midgrade;
    int fingrade;
    int n;
    std *head=NULL;

    while(1){
        printf("\n0:Exit\n1:Add new record\n2:Print list\n3:Update record\n4:Calculate class's average\n5:Print top student by average\n");
        scanf("%d",&n);
        switch(n){
            case 0:
                exit(0);
            case 1:
                printf("Enter student number: ");
                scanf("%d",&sn);
                printf("Enter name: ");
                scanf("%s",ns);
                printf("Enter midgrade: ");
                scanf("%d",&midgrade);
                printf("Enter fingrade: ");
                scanf("%d",&fingrade);
                head=Addnewrecord(head,sn,ns,midgrade,fingrade);
                break;
            case 2:
                Printlist(head);
                break;
            case 3:
                printf("Enter the number of the student to be updated: ");
                scanf("%d",&find);
                printf("Enter the new student number: ");
                scanf("%d",&sn);
                printf("Enter the new name: ");
                scanf("%s",ns);
                printf("Enter the new midgrade: ");
                scanf("%d",&midgrade);
                printf("Enter the new fingrade: ");
                scanf("%d",&fingrade);
                head=Updaterecord(head,find,sn,ns,midgrade,fingrade);
                break;
            case 4:
                calculateclassaverage(head);
                break;
            case 5:Printtopstudentbyaverage(head);

                break;
        }

    }

    return 0;
}
