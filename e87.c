// Function that raises an integer to a positive integer power.

#include <stdio.h>

long int x_to_the_n (int x, int n)
{
	int i;
	long int product=1;
	
	for (i=0; i<n; ++i) {
		product *= x;
	}
	
	return product;
		
}

int main (void)
{
	long int x_to_the_n (int x, int n);
	int base, power;
	
	printf("What is the base?\n");
	scanf("%i", &base);
	
	printf("What is the power?\n");
	scanf("%i", &power);
	
	
	printf("%i raised to %i is %li\n", base, power, x_to_the_n (base, power));
	
	return 0;
}