//compare library functions with the funtions I created in exercise 6, 7 and 8

#include <stdio.h>
#include <ctype.h>

int main (void)
{
	char c;
	
	printf ("Enter a character: ");
	scanf ("%c", &c);
	
	printf ("%i\n", isupper(c));
	printf ("%i\n", isalpha(c));
	printf ("%i\n", isdigit(c));
	
	return 0;
}