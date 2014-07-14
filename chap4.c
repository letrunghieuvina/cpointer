#include <stdio.h>

char* trim(char* phrase);
void display2DArray(int *arr, int rows, int cols);

int main()
{
	/*
	char* str = "  a cat  ";
	char* buffer = (char*)malloc(strlen(str));
	strcpy(buffer, str);
	str = trim(buffer);
	printf("__%s__", str);
	free(str);
	*/
	
	/*
	int arr[2][5] = {{4,5,7,8}, {3,9,1,2}};
	display2DArray(&arr, 2, 5);
	*/
	
	int a1[] = {1,2,3};
	int a2[] = {5,6,7};
	
	int *a3[] = {a1, a2};

	int rows = 2;
	int cols = 3;
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			printf("%d ", a3[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void display2DArray(int *arr, int rows, int cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			printf("%d ", *(arr + (i * cols) + j));
		}
		printf("\n");

	} 
}


char* trim(char* phrase)
{
	char* old = phrase;
	char* new = phrase;
	char* oldEnd = NULL;
	char* oldBegin = NULL;

	int lengthOfPhrase = strlen(phrase);
	oldEnd = phrase  + lengthOfPhrase - 1;

	while(*old == ' ')
	{
		old++;
	}
	oldBegin = old;

	while(*oldEnd == ' ')
	{
		oldEnd--;
	}

	while(old <= oldEnd)
	{
		*new++ = *old++;
	}

	*new = 0;
	return (char*)realloc(phrase, oldEnd - oldBegin + sizeof(char));
}
