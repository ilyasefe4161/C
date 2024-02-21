#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *ns;
    ns=(char*)malloc(22*sizeof(char));
    strcpy(ns, "ilyas efe sarisuleyman");
    puts(ns);
        free(ns);

    return 0;
}
