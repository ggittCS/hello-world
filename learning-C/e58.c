// Using nested for loops

#include <stdio.h>

int main(void)
{
	int n, number, triangularNumber, counter, count;
	
	printf("How many triangular numbers do you want calculated?\n");
	scanf("%i", &count);
	
	for ( counter=1; counter<=count; ++counter) {
		printf("What triangular number do you want? ");
		scanf ("%i", &number);
		
		triangularNumber = 0;
		
		for ( n=1; n<=number; ++n)
			triangularNumber += n;
		
		printf("Triangular number %i is %i\n\n", number, triangularNumber);
	}
	
	
	
	return 0;
}