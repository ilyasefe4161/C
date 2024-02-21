#include<stdio.h>
#include<time.h>

struct student{
    char ns[40];
    int point;
}std;

void createfiles(FILE *sequential, FILE *random){
    sequential=fopen("sequential.dat","w");
    random=fopen("random.dat","w");
    if(sequential==NULL)
        printf("the sequential file couldnt be open.");
    if(random==NULL)
        printf("the sequential file couldnt be open.");
}

void addrecordrandom(FILE *random, char ns[40], int point){

}

void addrecordsequential(FILE *sequential, char ns[40], int point){

}

void addtenpointrandomfile(FILE *random){

}

void printrandomfile(FILE *random){

}

void printsequentialfile(FILE *sequential){

}


void updatearecordrandom(FILE *random){

}


void updatearecordsequential(FILE *sequential){

}

void deletearecordrandom(FILE *random){

}

void deletearecordsequential(FILE *sequential){

}

int main(){
    int n,nn,nnn;
    FILE *sequential, *random;
    sequential=fopen("sequential.dat","r+");
    random=fopen("random.dat","r+");
    if(sequential==NULL)
        printf("the sequential file couldnt be open.");
    if(random==NULL)
        printf("the sequential file couldnt be open.");

    while(1){
        printf("\n0:exit\n1:create files\n2:add record by comparing points\n3:add ten point random file\n4:print random file \n5:print sequential file\n6:Update a record\n7:Delete a record\n");
        scanf("%d",&n);
        switch(n){
            case 0: exit(0); fclose(random); fclose(sequential);
            case 1:createfiles(sequential, random);break;
            case 2:printf("enter name surname");
                gets(std.ns);
                gets(std.ns);
                srand(time(NULL));
                std.point=rand()%100;
                if(std.point<50)
                    addrecordrandom(random, std.ns, std.point);
                else
                    addrecordsequential(sequential, std.ns, std.point);
                break;
            case 3:addtenpointrandomfile(random);
                break;
            case 4:printrandomfile(random); //ilk satırda 1.öğrenci, 2.satırda 1.ve 2. öğrenci, 3.satırda 1.,2.ve 3.öğrenci...
                break;
            case 5:printsequentialfile(sequential); //ilk satırda 1.öğrenci, 2.satırda 1.ve 2. öğrenci, 3.satırda 1.,2.ve 3.öğrenci...
                break;
            case 6:printf("1:random file\n2:sequential file\n");
                scanf("%d",&nn);
                if(nn=1)
                    updatearecordrandom(random);
                else
                    updatearecordsequential(sequential);
                break;
            case 7:printf("1:random file\n2:sequential file\n");
                scanf("%d",&nn);
                if(nnn=1)
                    deletearecordrandom(random);
                else
                    deletearecordsequential(sequential);
                break;
            default: printf("\n!!! enter from 0 to 6 !!!\n");
        }
    }
    return 0;
}
