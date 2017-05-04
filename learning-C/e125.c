// Function for bit_test and bit_set

#include <stdio.h>

int bit_test (unsigned int word, int n)
{
	if (n < 0 || n > 31)
		return 0;
	
	if (( word >> (31 - n)) & 0x1 )
		return 1;
	else
		return 0;
}

unsigned int bit_set (unsigned int word, int n)
{
	if (n < 0 || n > 31)
		return 0;
	return word | (1 << (31 - n));
}

int main (void)
{
	unsigned int x = 255, y = 48, z;
	int a, b, c, d;
	
	a = bit_test(x, 31-7);
	b = bit_test(x, 31-10);
	c = bit_test (y, 31-5 );
	d= bit_test (y, 31-2);
	
	printf ("%i\n", a);
	printf ("%i\n", b);
	printf ("%i\n", c);
	printf ("%i\n", d);
	
	z = bit_set (y, 31-1);
	
	printf ("%i\n", z);
	
	return 0;
}