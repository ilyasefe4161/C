#include <stdio.h>

#define g 10

int biggest(int arr[]);

int main(){

    int input[g],n1,n2;
    printf("enter 10 array elements \n");
    for(int i = 0 ; i<g; i++){
        scanf("%d",&input[i]);
    }

    n1 = biggest(input);
    n2 = biggest(input);

    printf("\n Biggest first two numbers = %d and %d \n",n1,n2);

    return 0;
}

int biggest(int arr[])
{

    int max = 0;

    for(int i = 0; i < g ; i++){
        
        if(arr[i]> max){
            max = arr[i];
        }
    }

    for (int j = 0; j<g;j++){
        if (arr[j] == max){
            arr[j] = 0;

        }
    }

    return max;
}