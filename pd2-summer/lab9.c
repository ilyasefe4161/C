#include<stdio.h>
/*
enum sanfoundry{a,b,c};
enum sanfoundry g;
int main(){
    g++;
    printf("%d",g);
}
*/
/*
enum day{a,b,c=5,d,e};
int main(){
    printf("enter number: ");
    scanf("%d",a);
    printf("%d",a);
    return 0;
}
*/
/*
enum sanfoundry{c=0,d=10,h=20,s=3}a;
int main(){
    a=c;
    printf("size of enum variable = %d bytes",sizeof(a));
    return 0;
}
*/
/*
enum sanfoundry{a,b,c=5};
int main(){
    enum sanfoundry s;
    b=10;
    printf("%d ",b);
    return 0;
}
*/
struct student{
    int number;
    char name[100];
    char surname[100];
    int midgrade;
};

enum sanfoundry{a=1,b};
enum sanfoundry1{c,d};
int main(){
    struct student students[10];
    enum sanfoundry1 s1=c;
    enum sanfoundry1 s=a;
    enum sanfoundry s2=d;
    printf("%d ",s);
    printf("%d ",s1);
    printf("%d ",s2);
    printf("Enter your name: ");
    gets(students->name);
    return 0;
}
