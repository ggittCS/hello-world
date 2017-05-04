// Function for bitpat_search

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
	
	return (size - 1);
}

// function to calculate the min number of bits needed to represent a value

int numberOfBits (unsigned int x)
{
	int sizeOfInt = int_size();
	int counter = 0;
	unsigned int temp = 1 << (sizeOfInt - 1);
	while ((temp | x ) != x) {
		temp = temp >> 1;
		counter ++;
	}
	
	return sizeOfInt - counter;
}

// function to return the n right most bits

int right_most (int pattern, int n)
{
	int temp, rightMost;
	
	temp = ~0;
	temp = temp << n;
	temp = ~temp;
	rightMost = pattern & temp;
	
	return rightMost;
}

/* The function searches the integer source, starting at the leftmost bit, to 
see if the rightmost n bits of pattern occur in source.
	algo:
		1) Get the n right most bits of pattern (pRightMost)
		2) Get the number of bits in source (sourceBits)
		3) set index to (sourceBits - n)
		4) if the n right most bits of source xor with pRightMost == 0, return index
		5) right shift source by 1 bits and decrease index by 1, if n<0 return -1, else go to step 4.
		*/
		
int bitpat_search (unsigned int source,  int pattern, int n)
{
	int pRightMost, sourceBits, index, res;
	
	pRightMost = right_most (pattern, n);
	sourceBits = numberOfBits (source);
	index = (sourceBits - n);
	res = -1;
	while (index >= 0) {
		if ((right_most (source, n) ^ pRightMost) == 0)
			res = index;
		source = source >> 1;
		index = index - 1;
	}
	
	return res;
	
}

// main function to test

int main (void)
{
	int index, source, pattern, n;
	
	printf ("Enter 3 ints (source pattern n) : ");
	scanf ("%i %i %i", &source, &pattern, &n);
	printf ("The %i most bits of %i is %i\n", n, pattern, right_most(pattern, n));
	index = bitpat_search (source, pattern, n);
	printf ("Pattern is at index %i\n", index);
	
	return 0;
}