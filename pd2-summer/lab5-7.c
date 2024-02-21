#include <stdio.h>
int main()
{
    char a[]="w3resource", *s;
    s=a;
    while(*s != '\0'){
        s++;
    }
    s--;
    while(*s != '\0'){
        printf("%c", *s);
        s--;
    }


    return 0;
}

