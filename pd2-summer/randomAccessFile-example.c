#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
    char name[20];
    int age;
    char illness[50];
};

void InsertPatient(FILE *file) {
    struct patient new_patient = {"", 0, ""};

    printf("Enter your name: ");
    scanf("%19s", new_patient.name);
    printf("Enter your age: ");
    scanf("%d", &new_patient.age);
    printf("Enter your illness: ");
    scanf("%49s", new_patient.illness);

    fseek(file, 0, SEEK_END);
    fwrite(&new_patient, sizeof(struct patient), 1, file);
    rewind(file);
}

void FindPatient(FILE *file) {
    struct patient current_patient;
    char findName[20];
    printf("Which patient do you want to search? Enter the name: ");
    scanf("%19s", findName);
    fseek(file, 0, SEEK_SET);
    while (fread(&current_patient, sizeof(struct patient), 1, file) == 1) {
        if (strcmp(current_patient.name, findName) == 0)
            printf("%-10s%-10d%-15s\n", current_patient.name, current_patient.age, current_patient.illness);
    }
}

void DeletePatient(FILE *file) {
    char findName[20];
    struct patient empty, deleted = {"", 0, ""};
    printf("Which patient do you want to delete? Enter the name: ");
    scanf("%19s", findName);
    fseek(file, 0, SEEK_SET);
    while (fread(&empty, sizeof(struct patient), 1, file) == 1) {
        if (strcmp(empty.name, findName) == 0) {
            printf("This patient will be deleted: %-10s%-10d%-15s\n", empty.name, empty.age, empty.illness);
            fseek(file, -sizeof(struct patient), SEEK_CUR);
            fwrite(&deleted, sizeof(struct patient), 1, file);
            rewind(file);
            printf("Patient deleted successfully.\n");
            return;
        }
    }
    printf("Patient with name '%s' not found.\n", findName);
}

void ModifyPatient(FILE *file) {
    char findName[20];
    struct patient current_patient;
    struct patient updated_patient = {"", 0, ""};

    printf("Which patient do you want to update? Enter the name: ");
    scanf("%19s", findName);
    fseek(file, 0, SEEK_SET);

    while (fread(&current_patient, sizeof(struct patient), 1, file) == 1) {
        if (strcmp(current_patient.name, findName) == 0) {
            printf("Current patient information:\n");
            printf("Name: %-10s Age: %-10d Illness: %-15s\n", current_patient.name, current_patient.age, current_patient.illness);

            printf("Enter the updated name: ");
            scanf("%19s", updated_patient.name);
            printf("Enter the updated age: ");
            scanf("%d", &updated_patient.age);
            printf("Enter the updated illness: ");
            scanf("%49s", updated_patient.illness);

            fseek(file, -sizeof(struct patient), SEEK_CUR);
            fwrite(&updated_patient, sizeof(struct patient), 1, file);
            rewind(file);
            printf("Patient information updated successfully.\n");
            return;
        }
    }
    printf("Patient with name '%s' not found.\n", findName);
}

void ListPatients(FILE *file) {
    struct patient list;
    printf("\n%-10s%-10s%-15s\n", "name", "age", "illness");
    fseek(file, 0, SEEK_SET);

    while (fread(&list, sizeof(struct patient), 1, file) == 1) {
        printf("%-10s%-10d%-15s\n", list.name, list.age, list.illness);
    }
}

int main() {
    int n;
    FILE *file;
    file = fopen("patient.dat", "r+");
    if (file == NULL)
        printf("The file couldn't be opened\n");
    while (1) {
        printf("\n0: exit\n1: Insert a patient\n2: Find a patient\n3: Delete a patient record\n4: Modify a patient record\n5: List all patients\n");
        scanf("%d", &n);
        switch (n) {
            case 0:
                fclose(file);
                exit(0);
            case 1:
                InsertPatient(file);
                break;
            case 2:
                FindPatient(file);
                break;
            case 3:
                DeletePatient(file);
                break;
            case 4:
                ModifyPatient(file);
                break;
            case 5:
                ListPatients(file);
                break;
            default:
                printf("!!! Enter a number from 0 to 5 !!!\n");
        }
    }
    return 0;
}
