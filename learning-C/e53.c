//Program that generates every fifth triangular number

#include <stdio.h>

int main(void)
{
	int n, triangularNumber;
	
	printf("n		Triangular number\n");
	printf("-		-----------------\n");
	
	for (n=5; n<=50; n=n+5) {
		triangularNumber = ((n*(n+1))/2);
		printf("%i		%i\n", n, triangularNumber);
	}
	
	
	
	return 0;
}