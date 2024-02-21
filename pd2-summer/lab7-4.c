#include<stdio.h>
#include<string.h>

int main(){
    char sentence[100],word=1;
    printf("enter a sentence: ");
    gets(sentence);
    //puts(sentence);

    int sentenceLength = strlen(sentence);

    for(int i=0;i<sentenceLength;i++){
        if(sentence[i]==' ')
            word++;
    }
    printf("%d",word);


    return 0;
}
