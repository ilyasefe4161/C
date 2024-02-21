#include<stdio.h>
#include<string.h>

int *fonk(char *p, int k){
    char *t=(char*)malloc(sizeof(char)), *s;
    s=p;
    int i=0;
        for(i=0;*(p+i)!='\0';++i){
        s=*(p+i);
        if(s >= '0' && s <= '9'){
            s+=k;
            if(s > '9'){
                s=s-'9'+'0'-1;
            }
            *(t+i)=s;
        }
    }
    return t;
}
int main(){
    char p[100],*s;
    int k;
    printf("Number: ");
    gets(p);
    printf("Key= ");
    scanf("%d",&k);
    s=fonk(p,k);
    puts(s);
    return 0;
}
