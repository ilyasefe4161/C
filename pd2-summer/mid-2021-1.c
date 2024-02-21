#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int sn=2010213027,sumSN=0,temp;
    char name[]="ilyas", *dName;
    dName=(char*)malloc(strlen(name)*sizeof(char));

    //puts(name);

    dName[0]='i';
    dName[1]='l';
    dName[2]='y';
    dName[3]='a';
    dName[4]='s';

    //printf("%s",dName);

    while(sn!=0){
        temp=sn%10;
        sumSN+=temp;
        sn/=10;
    }

    //printf("%d",sumSN);

    dName=(char*)realloc(dName,(sumSN-5)*sizeof(char));

    for (int i = 0; i < (sumSN-6); i++) {
        strcat(dName, name);
    }
    printf("Son ad: %s\n", dName);

    free(name);
    return 0;
}
