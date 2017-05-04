/* Program to calculate the 200th triangular number
Introduction of the for statement	*/

#include <stdio.h>

int main(void)
{
	int n=1, triangularNumber;
	
	triangularNumber=0;
	
	while(n<=200) {
		triangularNumber = triangularNumber + n;
		n++;
	}
	
	printf("The 200th triangular number is %i\n", triangularNumber);
	
	
	return 0;
}