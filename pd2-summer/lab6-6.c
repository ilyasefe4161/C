#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseWord(char *word, int length) {
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

int main() {
    char s[] = "I love Programming Languages course", ss[1000], word[100];
    int sLength = strlen(s), j = 0, wordLength = 0;

    for (int i = sLength - 1; i >= 0; i--) {
        if (s[i] == ' ' || i == 0) {
            if (i == 0) {
                word[wordLength] = s[i];
                wordLength++;
            }

            reverseWord(word, wordLength);
            for (int k = 0; k < wordLength; k++) {
                ss[j] = word[k];
                j++;
            }

            if (i != 0) {
                ss[j] = ' '; // Add space after each word
                j++;
            }

            wordLength = 0;
        } else {
            word[wordLength] = s[i];
            wordLength++;
        }
    }

    ss[j] = '\0'; // Add null-terminator at the end

    printf("Original sentence: %s\n", s);
    printf("Reversed sentence: %s\n", ss);

    return 0;
}
