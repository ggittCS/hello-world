// Program to create the maximum of 3 numbers

#include <stdio.h>

#define MAX3(x,y,z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)) )

int main (void)
{
	int a = 11, b = 7, c = 4;
	
	printf ("%i\n", MAX3(a,b,c));
	
	return 0;
}