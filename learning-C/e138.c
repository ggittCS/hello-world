// Macro to see whether a character is special using two other macros

#include <stdio.h>

#define IS_UPPER_CASE(x) (((x) >= 'A' && (x) <= 'Z') ? 1 : 0)
#define IS_LOWER_CASE(x) (((x) >= 'a' && (x) <= 'z') ? 1 : 0)
#define IS_ALPHABETIC(x) ((IS_UPPER_CASE(x) || IS_LOWER_CASE(x))  ? 1 : 0)
#define IS_DIGIT(x) (((x) >= '0' && (x) <= '9') ? 1 : 0)
#define IS_SPECIAL(x) ((IS_ALPHABETIC(x) || IS_DIGIT(x)) ? 0 : 1)

int main (void)
{
	char c;
	
	printf ("Enter char c: ");
	c = getchar();
	
	if (IS_SPECIAL(c))
		printf ("%c is a special character\n", c);
	else
		printf ("%c is not a special character\n", c);
	
	return 0;
}