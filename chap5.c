#include <string.h>
#include <stdio.h>

#define NAMENUM 5
#define NAMELENGTH 10

void readNames(char *(*names)[NAMENUM])
{
	for(int i = 0; i < NAMENUM; ++i)
	{
		*names[i] = (char*) malloc(NAMELENGTH);
	}
	for(int i = 0; i < NAMENUM; ++i)
	{
		printf("Enter name num#%d:", i);
		scanf("%s", *names[i]);
		printf("\n%s\n", *names[i]);
	}
	printf("end of readNames()");
}

int main()
{
	char *names[NAMENUM];
	
	for(int i = 0; i < NAMENUM; ++i)
	{
		names[i] = (char*) malloc(NAMELENGTH);
	}
	for(int i = 0; i < NAMENUM; ++i)
	{
		printf("Enter name num#%d:", i);
		scanf("%s", names[i]);
		printf("\n");
	}
	
	//readNames(&names[0]);
	
	for(int i = 0; i < NAMENUM; i++)
	{
		printf("%s\n", names[i]);
	}
	for(int i = 0; i < NAMENUM; i++)
	{
		free(names[i]);
	}
	printf("\nend of main()");
	return 0;
}
