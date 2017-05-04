// Function to calculate the nth triangular number

#include <stdio.h>

int calculateTriangularNumber (int n)
{
	int i, triangularNumber = 0;
	
	for (i=1; i<=n; ++i)
		triangularNumber +=i;
	
	printf ("Triangular number %i is %i\n", n, triangularNumber);
	
	return triangularNumber;
}

int main(void)
{
	int counter;
	int calculateTriangularNumber (int n);
	int number;
	
	for ( counter=1; counter<=5; ++counter) {
		printf("What triangular number do you want? ");
		scanf ("%i", &number);
		
		calculateTriangularNumber (number);
	}
	
	
	
	return 0;
}