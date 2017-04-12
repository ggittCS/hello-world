//Macro to see if printint works

#include <stdio.h>

#define printint(n)  printf ("%i\n", x ## n)

int main (void)
{
	int i, x1= 3, x2 = 4, x3 = 5, x4 = 6, x5 = 7;
	
	for (i=1; i<6; ++i)
		printint(i);
	
	return 0;
}