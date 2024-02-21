#include <stdio.h>

int f(int n, int nn){
    if(n==0)
        return 0;
    else
        return nn+f(n-1,nn);
}

int main(){
    int n,nn;
    printf("enter a number: ");
    scanf("%d",&n);
    printf("enter a number: ");
    scanf("%d",&nn);
    printf("Multiplication = %d",f(n,nn));
    return 0;
}
