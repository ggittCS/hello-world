// Program to see if two integers divide into each other evenly

#include <stdio.h>

int main (void)
{
	int a, b;
	
	printf("Type in two integers.\n");
	scanf("%i %i", &a, &b);
	
	if((a%b == 0))
		printf("Your two numbers are evenly divisible!\n");
	else
		printf("Your two numbers are not evenly divisible\n");
	
	
	
	return 0;
}