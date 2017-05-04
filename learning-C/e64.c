/* Program that acts as a simple printing calculator in the form of "number operator"
and should use + - * / S E  */

#include <stdio.h>

int main (void)
{
	int loop;
	float number, accumulator=0;
	char operator;
	
	printf("Begin calculations\n");
	
	
	
	for (loop=0; loop<=1000; loop++) {
		
		scanf("%f %c", &number, &operator);
		
		if (operator == 'S') {
			accumulator = number;
			printf("= %.6f\n", accumulator);
		}	
		else if (operator == 'E') {
			loop = loop +1000;
			printf("=%.6f\nEnd of calculations.\n", accumulator);			
		}
		else if (operator == '+') {
			accumulator = accumulator + number;
			printf("= %.6f\n", accumulator);
		}
		else if (operator == '-') {
			accumulator = accumulator - number;
			printf("= %.6f\n", accumulator);
		}
		else if (operator == '*') {
			accumulator = accumulator * number;
			printf("= %.6f\n", accumulator);
		}
		else if (operator == '/')
			if (number == 0) {
				loop = loop +1000;
				printf("Division by zero not allowed");
			}
			else
			{
				accumulator = accumulator / number;
				printf("= %.6f\n", accumulator);
			}
		else
		{
			loop = loop +1000;
			printf("Unknown operator.\n");
		}
	}
	
	
	return 0;
}