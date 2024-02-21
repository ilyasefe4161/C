#include <stdio.h>

int f(int a[], int n) {
    if(n==1) {
        return a[0];
    }
    else{
        int max=f(a, n-1);
        if (a[n-1] > max)
            return a[n-1];
        return max;
    }
}
int main(){
    int a[9] = {1,2,3,4,5,6,7,8,9};
    printf("Dizinin en buyuk elemani %d", f(a,9));
}
