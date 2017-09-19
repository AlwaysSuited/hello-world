#include <stdio.h>
#include <string.h>

int main ()
{
  int one = 0;
  int two = 0;
  int three = 0;
  int four = 0;
printf("Enter number one: ");
scanf("%d", &one);
printf("Enter number two: ");
scanf("%d", &two);
printf("Enter number three: ");
scanf("%d", &three);
printf("Enter number four: ");
scanf("%d", &four);
int sum = one + two + three + four;
double average = sum/4.0;
printf("The sum of your numbers is %d and the average of your numbers is %lf.\n", sum, average);
return 0;
}
