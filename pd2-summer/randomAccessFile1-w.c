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

    file=fopen("customer.dat","w");
    printf("enter account no(1-100)(for exit enter zero): ");
    scanf("%d",&accountInfo.accountNo);
    while(accountInfo.accountNo!=0){
        printf("enter surname name and balance: ");
        fscanf(stdin,"%s %s %f",accountInfo.surname,accountInfo.name,&accountInfo.balance);
        fseek(file,(accountInfo.accountNo-1)*sizeof(struct customer),SEEK_SET);
        fwrite(&accountInfo,sizeof(struct customer),1,file);
        printf("enter account no: ");
        scanf("%d",&accountInfo.accountNo);
    }

    fclose;
    return 0;
}
