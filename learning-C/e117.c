// Program to sort an array of integers into ascending order

#include <stdio.h>

void sort (int *a, int n)
{
	int *aptr1, *aptr2;
	int temp;
	
	for ( aptr1 = a; aptr1 < a + n -1; ++aptr1)
		for ( aptr2 = aptr1 + 1; aptr2 < a + n; ++aptr2)
			if (*aptr1 > *aptr2) {
				temp = *aptr1;
				*aptr1 = *aptr2;
				*aptr2 = temp;
			}
}

int main (void)
{
	int i;
	int array[16] = {34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11};
	void sort (int *ptr, int n);
	int *pointer = array;
	
	printf("The array before the sort: \n");
	
	for (i=0; i<16; ++i)
		printf("%i ", array[i]);
	
	sort (pointer, 16);
	
	printf("\n\n The array after the sort: \n");
	
	for (i=0; i<16; ++i)
		printf("%i ", array[i]);
	
	printf("\n");
	
	return 0;
	
}