// Program to divide two integers but not allowing division by 0

#include <stdio.h>

int main (void)
{
	int a, b;
	
	printf("Type in two integers.\n");
	scanf("%i %i", &a, &b);
	
	if (b==0)
		printf("Division by zero not allowed.\n");
	else
		printf("%.3f", (float) a / b);
	
	
	return 0;
}