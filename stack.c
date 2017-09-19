#include <stdio.h>
#include <string.h>

int main ()
{
  printf("Enter your height in inches: ");
  int height = 0;
  scanf("%d", &height);
  double dollarHeight = 0.0043;
  double dollarStackHeight = 1.0/dollarHeight;
  double numberOfDollars = dollarStackHeight * (double) height;
  printf("If you entered %d inches for youre height, a stack of dollar bills that high is worth %lf dollars.\n", height, numberOfDollars);
  return 0;
}
