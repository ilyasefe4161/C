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
    struct customer emptyCustomer={0,"","",0.0};
    FILE *file;

    file=fopen("customer.dat","w");

    for(i=1;i<=100;i++){
        fwrite(&emptyCustomer,sizeof(struct customer),1,file);
    }
    fclose;
    return 0;
}
