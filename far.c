//THIS PROGRAM WAS CREATED BY DEVIN SCOTT BROWN
#include <stdio.h>
int main ()
{
  int twenties = 0;
  int tens = 0;
  int fives = 0;
  int ones = 0;
  int quarters = 0;
  int dimes = 0;
  int nickels = 0;
  int pennies = 0;
  //double billlength = 6.14;
  double Pdiameter = .750;
  double Ndiameter = .835;
  double Ddiameter = .705;
  double Qdiameter = .955;
  printf("Enter the number of $20s you have: ");
  scanf("%d", &twenties);
  printf("Enter the number of $10s you have: ");
  scanf("%d", &tens);
  printf("Enter the number of $5s you have: ");
  scanf("%d", &fives);
  printf("Enter the number of $1s you have: ");
  scanf("%d", &ones);
  printf("Enter the number of quarters you have: ");
  scanf("%d", &quarters);
  printf("Enter the number of dimes you have: ");
  scanf("%d", &dimes);
  printf("Enter the number of nickles you have: ");
  scanf("%d", &nickels);
  printf("Enter the number of pennies you have: ");
  scanf("%d", &pennies);
  int total = (twenties * 20) + (tens * 10) + (fives * 5) + (ones * 1);
  int total2 = (quarters*25) + (dimes*10) + (nickels*5) + (pennies*1);
  double totalB = (twenties+tens+fives+ones) * 6.14;
  double totalA = (Pdiameter * pennies) + (Ndiameter * nickels) + (Ddiameter * dimes) + (Qdiameter * quarters);

  printf("You have %d dollars in bills and %d cents in change.\n", total ,total2 );
  printf("The total length of your bills is %lf inches.\n", totalB);
  printf("The total length of your change is %lf inches\n",totalA );
  printf("Your money can go a total of %lf inches\n", totalB + totalA );
}
