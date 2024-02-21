#include<stdio.h>
#include<string.h>

int main(){
    char s1[100], s2[100];
    int b;
    printf("enter word(s1): ");
    gets(s1);
    printf("again enter word(s2): ");
    gets(s2);
    b=strcmp(s1,s2);
    if(b<0)
        printf("s1 is less than s2");
    else if(b>0)
        printf("s2 is less than s1");
    else
        printf("s2 is equal than s1");

    return 0;
}
