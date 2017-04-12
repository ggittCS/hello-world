// Macro to see whether a character is alphabetic using two other macros

#include <stdio.h>

#define IS_UPPER_CASE(x) (((x) >= 'A' && (x) <= 'Z') ? 1 : 0)
#define IS_LOWER_CASE(x) (((x) >= 'a' && (x) <= 'z') ? 1 : 0)
#define IS_ALPHABETIC(x) ((IS_UPPER_CASE(x) || IS_LOWER_CASE(x))  ? 1 : 0)

int main (void)
{
	char c = 'b', d = 'D', e = '9';
	
	printf ("%i\n", IS_ALPHABETIC(c));
	printf ("%i\n", IS_ALPHABETIC(d));
	printf ("%i\n", IS_ALPHABETIC(e));
	
	return 0;
}