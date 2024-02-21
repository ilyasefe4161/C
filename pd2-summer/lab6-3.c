#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *ns;
    ns=(char*)malloc(9*sizeof(char));
    strcpy(ns, "ilyas efe");
    puts(ns);
    ns=(char*)realloc(ns,10*sizeof(char));
    strcat(ns, "   sarisuleyman");
    puts(ns);
    free(ns);

    return 0;
}
