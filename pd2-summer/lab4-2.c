#include<stdio.h>

int f(int a[], int n){

        if(n<0)
            return 0;
        else if(a[n-1]%2!=0)
            return 1+f(a,n-1);
        else
            return f(a,n-1);
}

int main(){
    int a[6]={3,452,54,8,7,9};
    printf("there is/are %d odd number.",f(a,6));

return 0;
}
