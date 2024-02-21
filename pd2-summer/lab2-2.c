#include<stdio.h>

void bodyIndex(){
    int boy, kilo,bodyindex;
    printf("boy: ");
    scanf("%d",&boy);
    printf("kilo: ");
    scanf("%d",&kilo);
    bodyindex=kilo/(boy*boy);
    printf("kutle vucut endeksi: %d",bodyindex);
}

int main(){
    bodyIndex();
    return 0;
}
