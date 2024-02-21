#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i, sayi;

    srand(time(NULL));

    for(i = 0 ; i < 10 ; i++)
    {
        sayi = 10 + rand() % 5;
        printf("%d\t",sayi);
    }

    return 0;
}
