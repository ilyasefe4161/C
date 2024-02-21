#include <stdio.h>

int f(int a[], int n) {
    if(n==1) {
        return a[0];
    }
    else{
        int min=f(a, n-1);
        if (a[n-1] < min)
            return a[n-1];
        return min;
    }
}
int main(){
    int a[9] = {1,2,3,4,5,6,7,8,9};
    printf("Dizinin en kucuk elemani %d", f(a,9));
}
