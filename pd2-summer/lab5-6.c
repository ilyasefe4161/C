#include <stdio.h>

int main()
{
    char a[5]={2,3,4,5,6}, *p;
    p=a;
    int i=0,sum=0,n;

    printf("%d\n",sum);
    printf("%d\n",a[0]);
    printf("%d\n",*p);

    while(*p != '\0'){
        sum+=(*p);
        p++;
    }

    printf("The sum of array is : %d",sum);

    return 0;
}

