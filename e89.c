// Function to calculate the least common multiple

#include <stdio.h>

int gcd (int u, int v)
{
	int temp;
	
	while (v != 0) {
		temp = u%v;
		u = v;
		v = temp;
	}
	
	return u;
}

int lcm (int u, int v)
{
	int result;
	
	result = ((u*v) / (gcd (u,v)));
	
	return result;
}

int main (void)
{
	int a, b;
	
	printf ("Give me two numbers!\n");
	scanf("%i %i", &a, &b);
	
	printf("The lcm of %i and %i is %i\n", a, b, lcm (a,b));
	
	return 0;
}