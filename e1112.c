// See what works

#include <stdio.h>

int main (void)
{
	char  *message = "Programming in C is fun\n";
	char  message2[] = "You said it\n";
	char  *format  = "x = %i\n";
	int   x = 100;
	
	printf ("x = %i\n", x);
	printf (format, x);
	printf ("%s", &format[0], x);
		
	return 0;
}