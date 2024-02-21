#include<stdio.h>

int main()
{
int Arr[] = {10,5,4,12};
int *Ap = Arr;
int **App = &Ap;
printf("output1 = %d\n", Ap[2]);
Ap ++;
printf("output2 = %d\n", *(Ap+2));
printf("output3 = %d\n", Ap+1);
(*App)++;
printf("output4 = %d\n", **App);
Ap =Ap-2;
printf("output5 = %d\n", *App);
    return 0;
}
