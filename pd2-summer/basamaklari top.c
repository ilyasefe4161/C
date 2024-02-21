#include<stdio.h>

int f(int n){
    if(n==0){
        return 0;
    }
    else{
        return n%10 + f(n/10);
    }
}

int main(){
    int n;
    printf("enter a number: ");
    scanf("%d",&n);
    printf("basamaklari toplami: %d",f(n));
    return 0;
}
