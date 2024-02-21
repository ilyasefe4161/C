#include<stdio.h>

int main(){
	char c;
	int a, sayma[26]={0}, chr,i;
	printf("enter a sentences: ");
	while((c=getchar())!='\n')
	{
		a=c-'a';
		if(a>=0 && a<26)
		sayma[a]++;
		else
		chr++;
	}
	printf("\ngirdiginiz cumle %d karakter iceriyor: \n",chr);
	for(i=0;i<26;i++)
	{
		printf("%d kez %c\n",sayma[i],'a'+i);
	}
	return 0;
}
