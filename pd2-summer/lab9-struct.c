#include<stdio.h>

struct student{
    int number;
    char name[100];
    char surname[100];
    int midgrade;
};

int main(){
    struct student students[10];
    int sn,i;
    printf("how many students do you have: ");
    scanf("%d",&sn);

    for(i=0;i<sn;i++){
        printf("Enter your student number: ");
        scanf("%d",&students[i].number);

        printf("Enter your name: ");
        gets(students[i].name);
        gets(students[i].name);

        printf("Enter your surname: ");
        scanf("%s",&students[i].surname);

        printf("Enter your midgrade: ");
        scanf("%d",&students[i].midgrade);
    }
 for(i=0;i<sn;i++){
    printf("\n%d",students[i].number);
    printf("\n%s",students[i].name);
//  puts(students->name);
    printf("\n%s",students[i].surname);
    printf("\n%d",students[i].midgrade);
 }
    return 0;
}
