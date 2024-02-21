#include<stdio.h>
#include<stdlib.h>

struct student{
    int sn;
    char ns[50];
    char department[50];
};
void Createafile(FILE *file){
    file=fopen("lab13-1.dat","w");
    if(file==NULL){
        printf("\n!!! The file couldnt be open !!!\n");
        return;
    }
    fclose(file);
}

void Addanewrecord(FILE *file){
    if(file==NULL){
        printf("\n!!! The file couldnt be open, firstly you have create a file !!!\n");
        return;
    }

    struct student std={0,"",""};
    printf("Enter your student number: ");
    scanf("%d",&std.sn);
    printf("Enter your name and surname: ");
    gets(std.ns);
    gets(std.ns);
    printf("Enter your department: ");
    gets(std.department);
    fseek(file,0*sizeof(struct student),SEEK_END);
    fwrite(&std,sizeof(struct student),1,file);
}

void Updatearecord(FILE *file){
    int searchSN;
    if(file==NULL){
        printf("\n!!! The file couldnt be open, firstly you have create a file !!!\n");
        return;
    }
    printf("Enter the student number which you will update: ");
    scanf("%d",&searchSN);
    fseek(file,0*sizeof(struct student),SEEK_SET);

    struct student std={0,"",""};
    while(!feof(file) && std.sn!=searchSN)
        fread(&std,sizeof(struct student),1,file);
    printf("Enter your student number for update: ");
    scanf("%d",&std.sn);
    printf("Enter your name and surname for update: ");
    gets(std.ns);
    gets(std.ns);
    printf("Enter your department for update: ");
    gets(std.department);
    fseek(file,-sizeof(struct student),SEEK_CUR);
    fwrite(&std,sizeof(struct student),1,file);
    fseek(file,0*sizeof(struct student),SEEK_SET);
}

void Deletearecord(FILE *file){
    int searchSN;
    if(file==NULL){
        printf("\n!!! The file couldnt be open, firstly you have create a file !!!\n");
        return;
    }
    printf("Enter the student number which you will delete: ");
    scanf("%d",&searchSN);
    fseek(file,0*sizeof(struct student),SEEK_SET);
    struct student std,empty={0,"",""};
    while(!feof(file)){
        fread(&std,sizeof(struct student),1,file);
        if(std.sn==searchSN){
            fseek(file,-sizeof(struct student),SEEK_CUR);
            fwrite(&empty,sizeof(struct student),1,file);
            break;
        }
    }
    fseek(file,0*sizeof(struct student),SEEK_SET);
}

void Printrecords(FILE *file){
    if(file==NULL){
        printf("\n!!! The file couldnt be open, firstly you have create a file !!!\n");
        return;
    }
    struct student std={0,"",""};
    fseek(file,0*sizeof(struct student),SEEK_SET);
    printf("\n%-20s%-30s%-50s\n","Student Number","Name and Surname", "Department");
    while(!feof(file)){
        fread(&std,sizeof(struct student),1,file);
        if(std.sn!=0)
            printf("%-20d%-30s%-50s\n",std.sn,std.ns,std.department);
    }
    fseek(file,0*sizeof(struct student),SEEK_SET);
}

void Textsequentialfile(FILE *file){
    struct student std={0,"",""};
    FILE *write=fopen("lab13-11.dat","w");
    if(write==NULL){
        printf("\n!!! The file couldnt be open !!!\n");
        return;
    }
    else{
        rewind(file);
        fprintf(write,"%-20s%-30s%-50s\n","Student Number","Name and Surname", "Department");
        fseek(file,0*sizeof(struct student),SEEK_SET);
        fread(&std,sizeof(struct student),1,file);
        while(!feof(file)){
            fread(&std,sizeof(struct student),1,file);
            if(std.sn!=0)
                fprintf(write,"%-20d%-30s%-50s\n",std.sn,std.ns,std.department);
        }
        fclose(write);
    }
}

int main(){
    int n;
    FILE *file=fopen("lab13-1.dat","r+");

    while(1){
        printf("\n0:exit\n1:Create a file\n2:Add a new record\n3:Update a record\n4:Delete a record\n5:Print records\n6:Text sequential file\n");
        scanf("%d",&n);
        switch(n){
            case 0:exit(0);fclose(file);
            case 1:Createafile(file);break;
            case 2:Addanewrecord(file);break;
            case 3:Updatearecord(file);break;
            case 4:Deletearecord(file);break;
            case 5:Printrecords(file);break;
            case 6:Textsequentialfile(file);break;
            default:printf("!!! Enter from 0(zero) to 6 !!!");
        }
    }
    fclose(file);
    return 0;
}
