//write to computes the factorial of a number, take a number, pass the input value to a func., inside the func. check if the number is greater than 0, 
//if true return number multiplied by a recursive  call to the func with parameters 1 less than number, otherwise return 1

#include<stdio.h>
int func(int x){
	if(x==0)
	{
		return 1;
	}
	else
	{
		return x*func(x-1);
	}
}
int main(){
	int n,i;
	printf("enter a positive number: ");
	scanf("%d",&n);
	if(n<0)
	{
		return printf("enter a positive number.");
	}
	printf("%d",func(n));
	return 0;
}
