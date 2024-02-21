#include <stdio.h>

int main()
{
    int a[3]={5,6,7},*ptr,i;
    ptr=a;

    while(*ptr != '\0'){
        printf("%d\n",*ptr);
        ptr++;
    }
    ptr--;
    printf("\n",*ptr);
    for(i=0;i<3;i++){
        printf("%d\n",*ptr);
        ptr--;
    }

    return 0;
}

