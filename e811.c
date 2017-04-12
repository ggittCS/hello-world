// Function that returns the sum of the elements in an array.

#include <stdio.h>

int arraySum (int x, int array[x])
{
	int i, sum=0;
	
	for (i=0; i<x; ++i)
		sum += array[i];
	
	return sum;
}

int main (void)
{
	int size, i;
	
	printf("How many numbers in the array?\n");
	scanf ("%i", &size);
	
	int array[size];
	int arraySum (int x, int array[x]);
	int sum;
	

	
	printf("What numbers do you want?\n");
	
	for (i=0; i<size; ++i)
		scanf ("%i", &array[i]);
	
	sum = arraySum (size, array);
	
	printf ("The sum of your array is %i\n", sum);
	
	return 0;
}