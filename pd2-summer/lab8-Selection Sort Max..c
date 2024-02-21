#include<stdio.h>

int selectionSort(int a[], int b){
    int i,j,index,max;
    for(i=0;i<b;i++){
        max=a[b-1];
        index=b-1;
        for(j=i;j<b-1;j++){
            if(a[j]>max){
                max=a[j];
                index=j;
            }
        }
        a[index]=a[i];
        a[i]=max;
    }
}

int main(){
    int a[7]={32,65,3,7,23,9,322};
    int i=0;
    selectionSort(a,7);
    printf("Selection Sort:");

    /*while(i<7){
        printf("\n%d",a[i]);
        i++;
    }*/

    for(i=0;i<7;i++){
        printf("\n%d",a[i]);
    }

    return 0;
}
