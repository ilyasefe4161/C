#include<stdio.h>

int main(){
    int i,n,*p;
    printf("Enter a number how many info do you want to save?: ");
    scanf("%d",&n);
    p=(int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        printf("Enter %d. number of array: ",i+1);
        scanf("%d",p+i);
    }
     for(i=0;i<n;i++){
        printf("\n%d. number: %d",i+1,*(p+i));
    }

    int max=*p;
     for(i=0;i<n;i++){
        if(*(p+i)>max)
            max=*(p+i);
    }

printf("\n%d",max);

    free(p);
    return 0;
}
