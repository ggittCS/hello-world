// Macro for absolute value

#include <stdio.h>

#define ABSOLUTE_VALUE(x) ((x) < 0 ? (-1 * (x)) : (x))

int main (void)
{
	int x = 5, y = -25, z = (y + x);
	
	printf ("%i\n", ABSOLUTE_VALUE(x));
	printf ("%i\n", ABSOLUTE_VALUE(y));
	printf ("%i\n", ABSOLUTE_VALUE(z));
	printf ("%i\n", ABSOLUTE_VALUE(x + y));
	
	return 0;
}