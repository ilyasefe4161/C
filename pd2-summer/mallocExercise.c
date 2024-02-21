#include<stdio.h>
#include<stdlib.h>
/*
int main(){
    int *dizi;
    int n,i;
    printf("enter number: ");
    scanf("%d",&n);
    dizi=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        printf("adress: %d\tValue: %d\n", &dizi[i],dizi[i]);
    }
    free(dizi);

    //while(getchar()!='\n'){};
        //getchar();
    return 0;
}
*/
/*
int main(){
    char giris[50];
    char *p;
    int i=0,k;
    p=giris;
    while(1){
        *(p+i)=getch();
        if(*(p+i)==13)
            break;
        putchar('*');
        printf("Adress[%d]: %d\n",i,p+i);
        i++;
    }
    printf("\n");
    for(k=0;k<i;k++){
        printf("Adress[%d]: %d\n",k,p+k);
        putchar(*(p+k));
    }
    getchar;
    return 0;
}
*/

int main(){
    char *p;
    int i=0,k;
    p=(char*)malloc(sizeof(char));
    while(1){
        *(p+i)=getch();
        if(*(p+i)==13) break;
        putchar('*');
        printf("Adress[%d]: %d\n",i,p+i);
        i++;
        p=(char*)realloc(p,(i+i)*sizeof(char));
    }

    printf("\n");

    for(k=0;k<i;k++){
        printf("Adress[%d]: %d\n",k,p+k);
        putchar(*(p+k));
    }
    free(p);
    getchar;
    return 0;
}
