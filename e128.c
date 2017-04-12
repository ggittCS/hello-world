// Function to set a specified set of bits to a particular value

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

void bitpat_set (unsigned int *data, unsigned int replace, int start, int count)
{
	unsigned int mask;
	int i;
	
	if (start < 0 || count < 0 || int_size() <= start || int_size() <= count)
		return;
	
	mask = 1;
	
	for (i = 0; i < count; i++)
		mask |= 1 << i;
	
	*data = ((*data | (mask << (int_size() - start - count))) 
		& ~(mask << (int_size() - start - count))) | (replace << (int_size() - start - count));
		
}

int main (void)
{
	unsigned int *data, x = 255;
	
	data = &x;
	
	bitpat_set (data, 0, 24, 3);
	
	printf ("%i\n", x);
	
	return 0;
}