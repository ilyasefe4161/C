#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,n;
	char sentence[30];
	FILE *dosya;
	
	dosya=fopen("udemy.txt","w");
	printf("Write a sentence: ");
	gets(sentence);
	printf("How many times do you want to write a sentence?\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("ok\n");
		fprintf(dosya,"%s\n",sentence);
	}
	
	return 0;
}
