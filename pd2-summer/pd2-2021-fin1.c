#include<stdio.h>
#include<stdlib.h>

void func(int sn){
    int tempn, *even, *odd, i = 0, j = 0;
    even = (int*)malloc(0*sizeof(int));
    odd = (int*)malloc(0*sizeof(int));

    while (sn != 0) {
        tempn = sn % 10;
        if (tempn % 2 == 0) {
            even = (int*)realloc(even, (i + 1) * sizeof(int));
            even[i] = tempn;
            i++;
        } else {
            odd = (int*)realloc(odd, (j + 1) * sizeof(int));
            odd[j] = tempn;
            j++;
        }
        sn = sn / 10;
    }
    printf("\nResult of even numbers:");
    for (int k = 0; k < i; k++) {
        printf(" %d", even[k]);
    }
    printf("\nResult of odd numbers:");
    for (int k = 0; k < j; k++) {
        printf(" %d", odd[k]);
    }
    free(even);
    free(odd);
}

int main() {
    int sn=2010213027;
    func(sn);
    return 0;
}
