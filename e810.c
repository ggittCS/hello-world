// Function that tells whether a number is prime or not

#include <stdio.h>

int prime (int x)
{
	int isPrime=1;
	int i;
	
	for (i=2; i<x && isPrime!=0; ++i)
		if ((x % i) == 0 ) 
			isPrime = 0;
		
	
	return isPrime;
}

int main (void)
{
	int number;
	
	printf ("Give me a number\n");
	scanf ("%i", &number);
	
	printf ("%i\n", prime (number));
	
	return 0;
}