#include<stdio.h>

int insertionSort(int a[],int b){
    int add,i,j;
    for(i=1;i<b;i++){
        add=a[i];
        for(j=i-1;j>=0 && add<=a[j];j--){
            a[j+1]=a[j];
        }
        a[j+1]=add;
    }
}

int main(){
    int a[7]={32,65,3,7,23,9,322};
    int i=0;
    insertionSort(a,7);
    printf("insertionSort:");

    /*while(i<7){
        printf("\n%d",a[i]);
        i++;
    }*/

    for(i=0;i<7;i++){
        printf("\n%d",a[i]);
    }

    return 0;
}
