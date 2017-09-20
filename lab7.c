//This program was created by Devin Brown
#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int rows, int cols)
{
	int **str =(int **) malloc(sizeof(int *)* rows);
	int i;
	for(i=0; i<rows; i++)
	{
		str[i] = malloc(sizeof(int) * cols);
	}
	return str;
}
void initMatrix(int **data, int rows, int cols)
{
	int i;
	int j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			data[i][j] = rand() % 1000;
		}
	}
}
int findRange(int **data, int rows, int cols)
{
	int i;
	int j;
	int max = data[0][0];
	int min = data[0][0];
	int range = 0;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			if(data[i][j] > max)
				max = data[i][j];
			if(data[i][j] < min)
				min = data[i][j];
		}
	}
	range = max-min;
	return range;
}
double findAverage(int **data, int rows, int cols)
{
	int i;
	int j;
	double average = 0;
	double sum = 0;
	int count = 0;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			sum = sum + data[i][j];
			count++;
		}
	}
	average = sum/(double)count;
	return average;
}
void printCorners(int **data, int rows, int cols)
{
	printf("%d %d\n", data[0][0], data[0][cols-1]);
	printf("%d %d\n", data[rows-1][0], data[rows-1][cols-1]);
}
int main(int argc, char *argv[])
{
	srand(0);
	int **data;
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);
	data = allocateMatrix(row, col);
	initMatrix(data, row, col);
	printf("Range of values in the array is %d\n", findRange(data, row, col) );
	printf("Average of all array values is %lf\n", findAverage(data, row, col) );
	printCorners(data, row, col);
	return 0;
}
