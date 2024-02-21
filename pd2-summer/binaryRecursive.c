#include <stdio.h>
#include <math.h>

int rev(int, int);

int main()
{
    int n;
    printf("enter a decimal number: ");
    scanf("%d",&n);
    printf("number: %d\tbinary: %d ",n,binary(n));
    return 0;
}

int binary(int n)
{
    if(n==0)
        return 0;
    else
        return (n%2)+10*binary(n/2);
}
