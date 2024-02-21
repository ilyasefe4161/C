#include<stdio.h>

int bubbleSort(int a[], int b){
    int temp,i,j;
    for(i=0;i<b-1;i++){
        for(j=0;j<b-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(){
    int a[7]={32,65,3,7,23,9,322};
    int i=0;
    bubbleSort(a,7);
    printf("bubbleSort:");

    /*while(i<7){
        printf("\n%d",a[i]);
        i++;
    }*/

    for(i=0;i<7;i++){
        printf("\n%d",a[i]);
    }

    return 0;
}
