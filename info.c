#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
	int main(){

	int num=0;
	int count=0;
	int sum=0;
	double average;
	int max=0;
	int min=0;
	printf("Enter series of numbers: ");
	scanf("%d", &num);
	max = num;
	min = num;
	while(num!=0)
	{
		sum = sum +num;
		count = count + 1;
		if (num>max)
		max=num;
		if (num<min)
		min = num;
		scanf("%d", &num);
		}
		average = (double)sum/(double)count;
		printf("Count of the numbers: %d\n", count);
		printf("Average of numbers: %lf\n", average);
		printf("Maximum value: %d\n", max);
		printf("Minimum value: %d\n", min);

		return 0;
		}
