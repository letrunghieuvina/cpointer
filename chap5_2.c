#include <string.h>
#include <stdio.h>

#define NAMENUM 5
#define NAMELENGTH 10

void readNames(char *names[NAMENUM])
{
 for(int i = 0; i < NAMENUM; ++i)
 {
  names[i] = (char*) malloc(NAMELENGTH + 1);// + 1 cho cái enter
 }
 for(int i = 0; i < NAMENUM; ++i)
 {
  printf("Enter name num#%d:", i);
  scanf("%s", names[i]);
  printf("\n");
 }
 
}

int main()
{
 char *names[NAMENUM];
 
 /*for(int i = 0; i < NAMENUM; ++i)
 {
  names[i] = (char*) malloc(NAMELENGTH);
 }
 for(int i = 0; i < NAMENUM; ++i)
 {
  printf("Enter name num#%d:", i);
  scanf("%s", names[i]);
  printf("\n");
 }*/
 
 readNames(&names);
 
 for(int i = 0; i < NAMENUM; ++i)
 {
  printf("%s\n", names[i]);
 }
 for(int i = 0; i < NAMENUM; ++i)
 {
  free(names[i]);
 }

 return 0;
}
