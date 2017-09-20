#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>



int main (void)
{

  srand(0);
  rand();
  int array[100];
  for (int i = 0; i<100;i++)
  {
    array[i]=0;
  }
  int size = 0;
  int count = 0;
  printf("How many random values to generate: ");
  scanf("%d", &size);
  printf("\n");
  for (int i = 0; i<size; i++)
  {
    int temp = rand()%100;
    array[temp]++;

  }

  for (int i = 0; i<100; i++)
  {
    if(array[i]!=0)
    {
      count++;
    }

  }
  printf("%d random numbers generated %d out of 100 possible values\n", size, count);
  return 0;
}
