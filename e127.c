// Function to extract a specified set of bits

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
	
	return (size);
}

unsigned int bitpat_get (unsigned int value, int n, int count)
{
	int word_size, i;
	
	word_size = int_size();
	
	if (n < 0 || n > word_size || count < 0 || count < 0 || count + n > word_size)
		return 0;
	
	// first shift value to the leftmost part of the word_size
	
	value <<= n;
	
	// now when we shift right, the bits to the left of the value will be cleared
	
	return value >> word_size - count;
}

int main (void)
{
	unsigned int x = 0xffffffff, y = 255, z;
	
	printf("%x\n", bitpat_get(x, 0, 1));
	printf("%x\n", bitpat_get(x, 31, 1));
	printf("%i\n", bitpat_get(y, 30, 2));
	
	z = bitpat_get (y, 24, 8);
	
	printf ("%i", z);
	
	return 0;
}