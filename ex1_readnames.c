#include <string.h>
#include <stdio.h>

#define NAMENUM 3
#define NAMELENGTH 10

//char* names[NAMENUM];

void readNames(char *(*names)[NAMENUM])
{
	//char* mnames[] = (char*[])(*names);
	
	printf("\n----------------------------- in readNames ^^! -------------------------------\n");
	printf("address of pointer to names before init = %p\n", &names);
	printf("value of names before init = %p\n", names);
	printf("address of each item in names before init:\n");
	for(int i = 0; i < NAMENUM; ++i)
	{
		printf("address of names[%d] = %p: %s\n", i, &(*names[i]), (*names)[i]);
	}
	printf("\n----------------------------- free old memory and allocate new memory -------------------------------\n");
	for(int i = 0; i < NAMENUM; ++i)
	{
		free((*names)[i]);
		(*names)[i] = (char*) malloc(NAMELENGTH);
	}
	for(int i = 0; i < NAMENUM; ++i)
	{
		printf("Enter name num#%d:", i);
		scanf("%s", (*names)[i]);
		//(*names)[i] = (char*) malloc(NAMELENGTH);
	}
}



int main()
{
	char *names[NAMENUM];
	printf("address of names before init = %p\n", &names);
	printf("address of each item in names before init:\n");
	for(int i = 0; i < NAMENUM; ++i)
	{
		printf("address of names[%d] = %p\n", i, &names[i]);
	}
	
	for(int i = 0; i < NAMENUM; ++i)
	{
		names[i] = (char*) malloc(NAMELENGTH);
	}
	printf("\n-----------------------------\n");
	printf("address of names after init = %p\n", &names);
	printf("address of each item in names after init:\n");
	for(int i = 0; i < NAMENUM; ++i)
	{
		printf("address of names[%p] = %p\n", i, &names[i]);
	}
	for(int i = 0; i < NAMENUM; ++i)
	{
		printf("Enter name num#%d:", i);
		scanf("%s", names[i]);
		//printf("\n");
	}
	printf("\n-----------------------------\n");
	printf("address of names after scanf = %p\n", &names);
	printf("address & value of each item in names after scanf:\n");
	for(int i = 0; i < NAMENUM; ++i)
	{
		printf("address of names[%d] = %p: %s\n", i, &names[i], names[i]);
	}
	printf("\n-----------------------------\n");
	
	readNames(&names);
	printf("\n----------------------------- print data after readNames() -------------------------------\n");
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
