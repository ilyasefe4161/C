#include <stdio.h>

int main(){
    int a=7, b=3;
    //int *aptr=&a;
    int *aptr; aptr=&a;
    int **bptr, ***cptr;

    *aptr=10;
    //aptr=&b;
    bptr=&aptr;
    cptr=&bptr;

    printf("a=%d\n", a);
    printf("aptr=%d\n", aptr);
    aptr++;
    printf("aptr++=%d\n", aptr);
    printf("*aptr=%d\n", *aptr);
    printf("*bptr=%d\n", *bptr);
    printf("**bptr=%d\n", **bptr);
    printf("**cptr=%d\n", **cptr);
    printf("***cptr=%d\n", ***cptr);
    printf("sizeof(a)=%d\n", sizeof(a));
    printf("sizeof(*aptr)=%d\n", sizeof(*aptr));
    printf("sizeof(aptr)=%d\n", sizeof(aptr));

    int dizi [6]={4,8,15,16,23,42};
    int *ptr;
    ptr = dizi; // ptr = &dizi[0];

    //*(ptr+0)=dizi[0];
    //*(ptr+1)=dizi[1];
    //*(ptr+2)=dizi[2];
    //*(ptr+3)=dizi[3];
    //*(ptr+4)=dizi[4];
    //*(ptr+5)=dizi[5];

    return 0;
}
