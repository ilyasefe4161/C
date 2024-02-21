#include <stdio.h>
int main()
{
    int a[5]={5,7,2,9,8},i;
    int *p;
    p=a;
    for(i=0;i<5;i++){
    printf("element - %d : %d\n",i, *(p+i));
    }

    return 0;
}

