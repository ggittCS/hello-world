// Macro to see whether a character is uppercase

#include <stdio.h>

#define IS_UPPER_CASE(x) (((x) >= 'A' && (x) <= 'Z') ? 1 : 0)

int main (void)
{
	char c;
	
	printf ("Enter char c: ");
	c = getchar();
	
	if (IS_UPPER_CASE(c))
		printf ("%c is upper case\n", c);
	else
		printf ("%c is lower case\n", c);
	
	return 0;
}