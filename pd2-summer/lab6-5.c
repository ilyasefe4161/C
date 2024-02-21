#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void f(int sn, int *odd, char *even){
    int evenIndex=0, oddIndex=0,temp;
    while(sn!=0){
        temp=sn%10;
        if(temp%2==0){
            even=(char*)realloc(even, (evenIndex +1)*sizeof(char));
            even[evenIndex]=temp + '0';
            evenIndex++;
        }
        else{
            odd=(int*)realloc(odd, (oddIndex+1)*sizeof(int));
            odd[oddIndex]=temp;
            oddIndex++;
        }
        sn/=10;
    }
    printf("Odd numbers: ");
    for (int i = oddIndex - 1; i >= 0; i--){
        printf("%d ", odd[i]);
    }
    printf("\n");

    printf("Even numbers: %s\n", even);
    free(odd);
    free(even);
}

int main(){
    int sn=2010213027, *odd;
    char *even;
    even=(char*)malloc(0);
    odd=(int*)malloc(0);

    f(sn,odd,even);

    return 0;
}

