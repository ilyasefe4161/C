#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *inputString;
    int *charCount;
    int length;

    printf("Enter a string: ");
    scanf("%[^\n]s", inputString);

    length = strlen(inputString);

    charCount = (int*)calloc(256,sizeof(int));

    for (int i = 0; i < length; i++) {
        charCount[(int)inputString[i]]++;
    }

    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 0) {
            printf("'%c' appears %d times\n", (char)i, charCount[i]);
        }
    }

    free(charCount);

    return 0;
}
