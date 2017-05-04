// function to sort three integers into ascending order

#include <stdio.h>

void sort3 (int *ptr1, int *ptr2, int *ptr3)
{
	int temp;
	
	if (*ptr1 > *ptr2) {
		temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
	}
	
	if (*ptr1 > *ptr3) {
		temp = *ptr1;
		*ptr1 = *ptr3;
		*ptr3 = temp;
	}
	
	if (*ptr2 > *ptr3) {
		temp = *ptr2;
		*ptr2 = *ptr3;
		*ptr3 = temp;
	}
		
}

int main (void)
{
	int a = 9, b = 5, c = 7;
	
	sort3 (&a, &b, &c);
	
	printf ("%i %i %i\n", a, b, c);
	
	return 0;
}