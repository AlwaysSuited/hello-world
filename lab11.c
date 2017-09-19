#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *allocateArray(int num)
{
	int *array = (int *)malloc(num * sizeof(int));
	return array;
}              // allocate space for a 1D array of N ints
void initializeArray(int *array, int num)
{
	for(int a=0; a<num; a++)
		array[a] = a;
	return;
}         // assign the values 0..(N-1) to the array
int sequentialSearch(int, int *, int);    // searches element 0, 1, 2, etc until found
int binarySearch(int num, int *array, int first, int last)
{


	// base case #1 - count not find, return -1
	if (first > last) return 0;

	// base case #2 - found it at the "mid" locatin, return that location
	int mid = (first + last) / 2;
	if (array[mid] == num)
		return 1;

	// two recursive cases - call BinarySearch with either lower half or upper half
	else if (array[mid] < num)
		return binarySearch(num, array, mid+1, last);
	else
		return binarySearch(num, array, first, mid-1);
}   // implement the BinarySearch algorithm
int main(int argc, char *argv[]) {
        srand(0);
        int size = atoi(argv[1]);
        printf("Building an array of integers from 0 to %d\n\n", size-1);
        int *data = allocateArray(size);
        initializeArray(data, size);
        printf("Performing 1 million sequential searches for a number in the array\n");
        clock_t begin1 = clock();
                for (int a=0; a<1000000; a++) {
                        int num = rand() % size;
                        sequentialSearch(num, data, size);
                }
        clock_t end1 = clock();
        printf("\nPerforming 1 million binary searches for a number in the array\n\n");
        clock_t begin2 = clock();
                for (int a=0; a<1000000; a++) {
                        int num = rand() % size;
                        binarySearch(num, data, 0, size-1);
                }
        clock_t end2 = clock();
        double timeSequential = (double) (end1-begin1) / CLOCKS_PER_SEC;
        double timeBinary = (double) (end2-begin2) / CLOCKS_PER_SEC;
        printf("Done\n\n");
        printf("%lf seconds for one million sequential searches\n", timeSequential);
        printf("%lf seconds for one million binary searches\n", timeBinary);
        return 0;
}
int sequentialSearch(int num, int *data, int size) {
        for (int a=0; a<size; a++)
                if (data[a] == num) return 1;
        return 0;
}
