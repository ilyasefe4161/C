#include<stdio.h>
int main(){
	int *n1,*n2,temp;
	n1=(int*)malloc(sizeof(int));
	n2=(int*)malloc(sizeof(int));
	printf("enter first number: ");
	scanf("%d",&*n1);
	printf("enter second number: ");
	scanf("%d",&*n2);
	
	printf("first number is %d	second number is %d\n",*n1,*n2);
	
	temp=*n1;
	*n1=*n2;
	*n2=temp;
	printf("after the changing:\n");
	printf("first number is %d	second number is %d",*n1,*n2);
	return 0;
}
