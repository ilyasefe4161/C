#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char a1[100], a2[100], *p;

    printf("write sth for array1: ");
    gets(a1);

    printf("write sth for array2: ");
    gets(a2);
    p=a1;
    strcat(p,a2);

    puts(p);

    puts(a1);
    puts(a2);


    return 0;
}
