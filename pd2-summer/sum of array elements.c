#include <stdio.h>

int SumOfElements(int a[], int n){
    if(n==0)
        return a[0];
    return a[n]+SumOfElements(a,n-1);
}

int main(){
    int n=5 ,a[5]={6,543,2,45,32};
    int sum=SumOfElements(a,n-1);
    printf("Sum = %d",sum);
    return 0;
}
