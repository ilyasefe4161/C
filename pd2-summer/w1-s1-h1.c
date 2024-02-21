#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(0));
    int d1=rand()%6+1;
    int d2=rand()%6+1;
    int sum1=d1+d2;
    printf("First Rolling:\nd1: %d\nd2: %d\nsum: %d",d1,d2,sum1);
    if(sum1==7 || sum1==11){
        printf("\nYou fail.");
    }
    else if(sum1==2 || sum1==3 || sum1==12){
            printf("\nYou win.");
        }
    else{
        int sum2;
        while(sum2!=sum1){
        d1=rand()%6+1;
        d2=rand()%6+1;
        sum2=d1+d2;
        printf("\nSecond Rolling:\nd1: %d\nd2: %d\nsum: %d",d1,d2,sum2);
        if(sum2==7){
            printf("\nYou fail.");
            exit(0);
        }
        else if(sum1==sum2)
            printf("\nYou win.");
        }
    }
    return 0;
    }
