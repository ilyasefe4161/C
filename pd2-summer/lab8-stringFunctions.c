#include<stdio.h>

int main(){
    char c[100]={"ilyas efe"};
    char cc[100]={"sarisuleyman"};
    char ccc[100]={"sarisuleyman"};
    int x,y;

    strcpy(c, "ilyasefe");
//    strcpy(c, cc);
    printf("After 'strcpy' c: %s",c);
    printf("\nAfter 'strcpy' cc: %s",cc);

    printf("\nString Length c: %d",strlen(c));
    printf("\nString Length cc: %d",strlen(cc));

    strcat(c, cc);
    printf("\nAfter 'strcat' c: %s",c);
    printf("\nAfter 'strcat' cc: %s",cc);

    printf("\nccc: %s",ccc);


    x=strcmp(c, cc);
    if(x<0)
        printf("\nc is less than cc");
    else if(x>0)
        printf("\ncc is less than c");
    else
        printf("\ncc is equal c");

    y=strcmp(ccc, cc);
    if(y<0)
        printf("\nccc is less than cc");
    else if(y>0)
        printf("\ncc is less than ccc");
    else
        printf("\nccc is equal c");


    return 0;
}
