#include<stdio.h>

hesapla(int sn,int p){
    int A[100];
    int i,point;
    int average, sum;
    int failStudent=0;
    for(i=0;i<sn;i++){
        printf("enter %d. student point: ",i+1);
        scanf("%d",&point);
        A[i]=point;
    }
    for(i=0;i<sn;i++){
        if(A[i]<p){
        failStudent++;
        }
        sum+=A[i];
        average=sum/sn;
    }
    printf("student number: %d\npassing point: %d\n",sn,p);
    printf("Sum: %d\nAverage: %d\n",sum,average);
    printf("fail student: %d\n",failStudent);
    }

int main(){
    int studentnumber, passingpoint;

    printf("enter student number: ");
    scanf("%d",&studentnumber);
    printf("enter passing point: ");
    scanf("%d",&passingpoint);
    hesapla(studentnumber,passingpoint);

    return 0;
}
