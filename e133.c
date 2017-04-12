// Create a macro for a minimum of two values

#include <stdio.h>

#define MIN(x,y) (((x) < (y)) ? (x) : (y))

int main (void)
{
	int a = 4, b = 6;
	
	printf (" %i\n", MIN(a,b));
	
	return 0;
}