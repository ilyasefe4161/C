#include<stdio.h>

int f(int n, int p){
    if(p==1)
        return n;
    else
        return n*f(n,p-1);
}

int main(){
    int n,p;
    printf("enter a number: ");
    scanf("%d",&n);

    printf("enter a number for power: ");
    scanf("%d",&p);

    printf("%d power %d = %d",n,p,f(n,p));

    return 0;
}
