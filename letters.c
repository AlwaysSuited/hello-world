#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main (void)
{
int array [26];
char input [100];
for (int i = 0; i<26;i++)
{
  array[i] = 0;
}
int len = 0;
printf("Enter your input: ");
scanf("%s", input);
while (! feof(stdin))
{
  len = strlen(input);
  for (int i = 0; i<len; i++)
  {
    if (input[i] == ' ')
      continue;
    array[input[i] - 97]++;
  }
  scanf("%s", input);
}
for (int i = 0; i<26; i++)
{
  if (array[i]==0)
  {
    printf("Your input did not contain all the letters\n");
    return 0;
  }
}
printf("Your input contained all the letters\n");
return 0;
}
