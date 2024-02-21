#include<stdio.h>
#include<string.h>

int main(){
    char sentence[100]="hello word", word[50];
    printf("enter a word to find: ");
    gets(word);
    puts(word);

    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);

    int found = 0;

    for (int i = 0; i <= sentenceLength - wordLength; i++) {
        int match = 1;
        for (int j = 0; j < wordLength; j++) {
            if (sentence[i + j] != word[j]) {
                match = 0;
                break;
            }
        }

        if (match) {
            found = 1;
            printf("Found at index %d\n", i);
        }
    }

    if (!found) {
        printf("Word not found in the sentence.\n");
    }
    return 0;
}
