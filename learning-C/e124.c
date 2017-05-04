// Program to illustrate rotation of integers

#include <stdio.h>

int main (void)
{
	unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u, w3 = 128;
	unsigned int rotate (unsigned int value, int n);
	
	printf ("%x\n", rotate (w1, 8));
	printf ("%x\n", rotate (w1, -16));
	printf ("%x\n", rotate (w2, 4));
	printf ("%x\n", rotate (w2, -2));
	printf ("%x\n", rotate (w1, 0));
	printf ("%x\n", rotate (w1, 44));
	printf ("%i\n", rotate (w3, -1));
	
	return 0;
}

// Function to rotate an unsigned int left or right

unsigned int rotate (unsigned int value, int n)
{
	unsigned int result, bits;
	int int_size (void);
	int size = int_size();
	
	//scale down the shift count to a defined range
	
	if (n > 0)
		n = n % size;
	else
		n = -(-n % size);
	
	if (n == 0)
		result = value;
	else if (n > 0) {	//left rotate
		bits = value >> (size - n);
		result = value << n | bits;
	}
	else {
		n = -n;
		bits = value << (size - n);
		result = value >> n | bits;
	}
	
	return result;
}

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