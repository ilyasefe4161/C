#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[20];
    char surname[20];
    int sn;
    int midgrade;
    int fingrade;
    FILE *file;
    file = fopen("sequentialFile.txt", "r");
    if (file == NULL)
        printf("File couldn't be opened.\n");
    printf("%-10s %-10s %-10s %-10s %-10s\n","name","surname","student number","midgrade","fingrade");
    fscanf(file, "%s %s %d %d %d", name, surname, &sn, &midgrade, &fingrade);
    while (!feof(file)){
        printf("%-10s %-10s %-14d %-10d %-10d\n",name, surname, sn, midgrade, fingrade);
        fscanf(file, "%s %s %d %d %d", name, surname, &sn, &midgrade, &fingrade);
    }
    rewind(file);
    fclose(file);
    return 0;
}
