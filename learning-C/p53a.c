// Program to generate a table of triangular numbers

#include <stdio.h>

int main(void)
{
	int n=1, triangularNumber;
	
	printf("TABLE OF TRIANGULAR NUMBERS\n\n");
	printf(" n		SUM from 1 to n\n");
	printf("---		---------------\n");
	
	triangularNumber=0;
	
	while(n<=10) {
		triangularNumber += n;
		printf(" %-2i		%i\n", n, triangularNumber);
		n++;
	}
	
	
	return 0;
}