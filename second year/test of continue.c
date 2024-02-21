#include <stdio.h>
 
int main()
{
	int i;
    for(i = 0; i < 5; i++)
    {
        if(i == 2){
            continue;
        }
        printf("%d. KOD BLOKLARI\n",i);
    }
    return 0;
}
