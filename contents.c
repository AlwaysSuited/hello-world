//THIS PROGRAM WAS CREATED BY DEVIN BROWN
/*THIS PROGRAM reads from standard input until end-of-file. Once it hits end-of-file, it tells the user what characters it
saw, ordered from the most-occurring character down to the characters that it did not see. */
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int main (void)
{
  char c[1000];
  int uppercase[26] = {0};
  int lowercase[26] = {0};
  int numbers[10] = {0};
  int special[32] = {0};
  int len = 0;
  int count = 0;
  //int value;
  int lower = 0;
  int specialcount = 0;
  int upper = 0;
  int digit = 0;
  int max = 0;

  /*for(int i = 0; i<26; i++)
  {
    uppercase[i]=0;
    //lowercase[i]=0;
  }
  for(int i = 0; i<10; i++)
  {
    numbers[i]=0;
  }
  for(int i = 0; i<32; i++)
  {
    special[i]=0;
  }
  */
  printf("Enter a series of strings using ctrl-D to exit: ");
  scanf("%s", c);
  while (! feof(stdin))
  {
    len = strlen(c);
    for(int i = 0; i<len; i++)
    {
      int temp = c[i];
      if (c[i]!=temp || c[i]== temp)
      {
        count++;
      }
    }
    for (int i = 0; i<len; i++)
    {

      if (c[i] >= 'a' && c[i] <= 'z')
      {
      lower++;
      lowercase[c[i]-'a']++;
      }
      else if (c[i] >= 'A' && c[i] <= 'Z')
      {
      upper++;
      uppercase[c[i]-'A']++;
      }
      else if (c[i] >= '0' && c[i] <= '9')
      {
      digit++;
      numbers[c[i]-'0']++;
      }
      else
      {
      specialcount++;
      special[c[i]-'!']++;
      }
    }
    scanf("%s", c);
  }

 for(int i = 0; i<26; i++)
  {
    if(lowercase[i]>max)
    max = lowercase[i];
  }
  for(int i = 0; i<26; i++)
  {
    if(uppercase[i]> max)
    max = uppercase[i];
  }
  for(int i = 0; i<10; i++)
  {
    if(numbers[i]>max)
    max = numbers[i];
  }
  for(int i = 0; i<32; i++)
  {
    if(special[i]>max)
    max = special[i];
  }
  printf("%d characters\n", count);
  printf("lowercase = %d and uppercase = %d and digit = %d and special = %d\n", lower, upper, digit, specialcount);
  for(int j = max; j>0;j--)
  {
    printf("Characters occuring %d times: ", max );
    max -= 1;
    for(int i = 0; i<26; i++)
    {
      if (lowercase[i]==j)
      {
        printf("%c ", i+'a');
      }
      if(uppercase[i]==j)
      {
        printf("%c ", i+'A');
      }
    }
    for(int i = 0; i<10; i++)
    {
      if(numbers[i]==j)
      {
        printf("%c ", i+'0');
      }
    }
    for(int i = 0; i<32; i++)
    {
      if(special[i]==j)
      {
        printf("%c ", i+'!');
      }
    }
    printf("\n");
    }
    printf("Characters not seen: ");
    for(int i = 0; i<26; i++)
    {
      if (lowercase[i]==0)
      {
        printf("%c ", i+'a');
      }
      if(uppercase[i]==0)
      {
        printf("%c ", i+'A');
      }
    }
    for(int i = 0; i<10; i++)
    {
      if(numbers[i]==0)
      {
        printf("%c ", i+'0');
      }
    }
    for(int i = 0; i<32; i++)
    {
      if(special[i]==0)
      {
        printf("%c ", i+'!');
      }
    }
    printf("\n");
  return 0;
}
