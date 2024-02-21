#include<stdio.h>

int f(int s){
    if(s==0){
        return 0;
    }
    else{
        return s+f(s-1);
    }
}

int main(){
    int sayi;
    printf("bir dogal sayi girin: ");
    scanf("%d",&sayi);
    printf("sayilarin toplami: %d",f(sayi));
    return 0;
}
