#include<stdio.h>
#include<string.h>
#define MAX 80

int main()
{
	char buff[MAX]="add 3 4" ;

	int i = 0;
	
	char *words[5];

	words[i] = strtok(buff," \n");

	while (words[i]!=NULL)
	{
		printf("words[%d] is %s\n", i, words[i]);
		i++;
		words[i] = strtok(NULL," \n");

	}

	return 0;
}
