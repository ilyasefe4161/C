#include <stdio.h>
int main()
{
    int n =5, nn=6, sum;
    int *p, *pp;
    p=&n;
    pp=&nn;

    sum=*p+*pp;
    printf("%d",sum);

    return 0;
}
