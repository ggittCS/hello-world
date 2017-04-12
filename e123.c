// Number of bits on my machine for a given number

#include <stdio.h>

int int_size (void)
{
	unsigned int bits;
	int size = 0;
	
	bits = ~0;
	
	while (bits) {
		++size;
		bits >>= 1;
	}
	
	return size;
}

int main (void)
{
	int x;
	int int_size (void);
	
	x = int_size ();
	
	printf ("%i\n", x);
	
	return 0;
}