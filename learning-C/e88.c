// Figuring out the roots to the quadratic equation

#include <stdio.h>

float absoluteValue (float x)
{
	if (x<0)
		x = -x;
	
	return (x);
}

// Function to compute the square root of a number

float squareRoot (float x)
{
	const float epsilon = .00001;
	float			guess = 1.0;
	
	while (absoluteValue (guess * guess - x) >= epsilon)
		guess = (x/ guess + guess) / 2.0;
	
	return guess;
}

float quadraticFormula1 (int a, int b, int c)
{
	float result;
	float determinant = (b*b - (4*a*c)) ;
	
	if (determinant < 0)
		printf("Roots are imaginary\n");
	else
		result = ((-b + squareRoot (determinant))/(2*a));
	
	return result;
}

float quadraticFormula2 (int a, int b, int c)
{
	float result;
	float determinant = (b*b - (4*a*c)) ;
	
	if (determinant < 0)
		printf("\n");
	else
		result = ((-b - squareRoot (determinant))/(2*a));
	
	return result;
}

int main (void)
{
	int a, b, c;
	
	printf("What is the value of a, b and c... use spaces\n");
	scanf("%i %i %i", &a, &b, &c);
	
	printf("The values of the quadratic equation are %f and %f\n", 
	quadraticFormula1 (a,b,c), quadraticFormula2 (a,b,c));
	
	return 0;
}