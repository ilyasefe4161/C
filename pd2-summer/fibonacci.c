#include <stdio.h>

int fibonacci(int n){
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(){
    int i, n;
    printf("How many fibonacci numbers do you want to see?:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        printf("%d ", fibonacci(i));
    }
    return 0;
}
