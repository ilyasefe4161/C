#include <stdio.h>
int main()
{
    char a[]="w3resource", *s,*ss;
    s=a;
    ss=a;
    int i=0;

    while(*s != '\0'){
        i++;
        *s++;
    }

    printf("The length of the given string '%s' is : %d",ss,i);

    return 0;
}

