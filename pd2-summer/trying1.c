#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    char *firstName = (char *)malloc(20 * sizeof(char)); // Allocate memory for the first name

    if (firstName == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign your name to the memory
    strcpy(firstName, "YourName");

    printf("Initial name: %s\n", firstName);

    int studentNumber;
    printf("Enter your student number: ");
    scanf("%d", &studentNumber);

    int sum = sumOfDigits(studentNumber);

    // Expand memory based on the sum of digits
    firstName = (char *)realloc(firstName, (sum + 1) * sizeof(char));

    if (firstName == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Assign your name to the expanded memory area
    strcpy(firstName, "YourName");

    printf("Expanded name: %s\n", firstName);

    free(firstName);

    return 0;
}
