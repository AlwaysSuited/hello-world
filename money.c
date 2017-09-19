#include <stdio.h>
#include <string.h>

int main ()
{
  int twenties = 0;
  int tens = 0;
  int fives = 0;
  int ones = 0;
  printf("Enter the number of $20s you have: ");
  scanf("%d", &twenties);
  printf("Enter the number of $10s you have: ");
  scanf("%d", &tens);
  printf("Enter the number of $5s you have: ");
  scanf("%d", &fives);
  printf("Enter the number of $1s you have: ");
  scanf("%d", &ones);
  int total = (twenties * 20) + (tens * 10) + (fives * 5) + (ones * 1);
  printf("The total number of bills you have is %d.\n", total );
return 0;
}
