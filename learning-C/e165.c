// Program to extract columns from each line of a filelength

#include <stdio.h>

int main (void)
{
	char inName[64];
	FILE *in;
	int m, n, curcol, c;
	
	printf ("Enter name of file: ");
	scanf ("%63s", inName);
	printf ("Enter starting and ending column numbers: ");
	scanf ("%i %i", &m, &n);
	
	if ( (in = fopen(inName, "r")) == NULL ) {
		printf ("Can't open %s for reading.\n", inName);
		return 1;
	}
	else {
		curcol = 1;
		
		while ( (c = getc(in)) != EOF ) {
			if (c == '\n') {
				putchar ('\n');
				curcol = 0;
			}
			else if (curcol >= m && curcol <= n)
				putchar (c);
			++curcol;
		}
	}
	
	return 0;
}