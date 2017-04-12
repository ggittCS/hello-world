// Program to generate the first 15 Fibonacci numbers

#include <stdio.h>

int main (void)
{
	int fib0=0, fib1=1, fib2, i;
	
	printf("0\n1\n");
	
	
	for (i=0; i<13; ++i) {
		fib2 = fib0 + fib1;
		printf("%i\n", fib2);
		fib0 = fib1;
		fib1 = fib2;
	}	
	

	return 0;
}