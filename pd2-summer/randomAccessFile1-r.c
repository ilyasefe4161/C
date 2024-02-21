#include<stdio.h>
#include<stdlib.h>

struct customer{
    int accountNo;
    char surname[25];
    char name[20];
    float balance;
};

int main(){
    int i;
    struct customer accountInfo={0,"","",0.0};
    FILE *file;

    file=fopen("customer.dat","r");
    printf("%-10s%-16s%-11s%10s\n","accountNo","surname","name","balance");
    while(!feof(file)){
        fread(&accountInfo,sizeof(struct customer),1,file);
        if(accountInfo.accountNo!=0){
            printf("%-10d%-16s%-11s%10.2f\n",accountInfo.accountNo,accountInfo.surname,accountInfo.name,accountInfo.balance);
        }
        fread(&accountInfo,sizeof(struct customer),1,file);
    }
    fclose;
    return 0;
}
