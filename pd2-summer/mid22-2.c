#include<stdio.h>

float func(int n){
    if(n==1){
        return 1.0;
    }
    else{
        return (1.0/n) + func(n-1);
    }
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("%f",func(n));
    return 0;
}
