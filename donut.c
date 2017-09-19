#include <stdio.h>
#include <string.h>

int main ()
{
  int boxes = 0;
  //int calories = 190;
  printf("Enter the number of doughnut boxes: ");
  scanf("%d", &boxes);
  int doughnuts = 12;
  int totalDoughnuts = boxes * doughnuts;
  int totalCalories = 190 * totalDoughnuts;
  printf("If you saw %d boxes of doughnuts, then you are looking at %d calories.\n", boxes, totalCalories);


  return 0;
}
