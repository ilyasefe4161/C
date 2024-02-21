#include <stdio.h>
#include <stdlib.h>

int main() {
    int sn = 2010213027, tempsn = sn, temp, *p, i, digits = 0;
    p = (int *)malloc(0);

    while (tempsn != 0) {
        tempsn /= 2;
        digits++;
    }

    tempsn = sn;

    for (i = 0; i < digits; i++) {
        p = (int *)realloc(p, (i + 1) * sizeof(int));
        p[i] = tempsn % 2;
        tempsn /= 2;
    }

    printf("Student No: %d Result: ", sn);
    for (i = digits - 1; i >= 0; i--) {
        printf("%d", p[i]);
    }
    printf("\n");

    free(p);

    return 0;
}
