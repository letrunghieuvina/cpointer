#include <stdio.h>

void readNames(char*** nameArray, int numberOfNames, int nameLength);

int main()
{
	int numberOfNames = 0; 
	int nameLength = 20;
	char** namesArray;
	
	printf("How many names to input? ");
	scanf("%i", &numberOfNames);

	readNames(&namesArray, numberOfNames, nameLength);	

	/*
	namesArray = (char**) malloc(sizeof(char*) * numberOfNames);
	
	for(int i = 0; i < numberOfNames; ++i)
	{
		namesArray[i] = (char*) malloc(nameLength);
	}

	for(int i = 0; i < numberOfNames; ++i)
	{
		printf("Input name #%i: ", i);
		scanf("%s", namesArray[i]);
	}
	*/
	printf("\nNow show the names input.\n");	

	for(int i = 0; i < numberOfNames; ++i)
	{
		printf("name #%i = %s\n", i, namesArray[i]);
	}
	
	printf("\nNow de-allocate memory");

	for(int i = 0; i < numberOfNames; ++i)
	{
		free(namesArray[i]);
	}

	free(namesArray);

	printf("\ndone");
}

void readNames(char*** nameArray, int numberOfNames, int nameLength)
{
	*nameArray = (char**) malloc(sizeof(char*) * numberOfNames);
	for(int i = 0; i < numberOfNames; ++i)
	{
		(*nameArray)[i] = (char*) malloc(nameLength);
	}

	for(int i = 0; i < numberOfNames; ++i)
	{
		printf("Enter name #%i: ", i);
		scanf("%s", (*nameArray)[i]);
	}
}
