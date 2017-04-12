// Macro to create a SHIFT like function

#include <stdio.h>

#define SHIFT(x,y) ((y) > 0 ? ((x) << (y)) : ((x) >> (-y)))


int main (void)
{
	unsigned int w1 = 255u, w2 = 127u;
	
	printf ("%i\t%i\n", SHIFT(w1,-2), w1 >> 2);
	printf ("%i\t%i\n", SHIFT(w1,2), w1 << 2);
	printf ("%i\t%i\n", SHIFT(w2,-1), w2 >> 1);
	printf ("%i\t%i\n", SHIFT(w2,1), w2 << 1);
	
	
	return 0;
}