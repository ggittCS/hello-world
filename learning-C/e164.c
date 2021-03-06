// Program that alternattes between copying lines from two different files and outputs to stdout

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *open (char filename[])
{
	FILE *f;
	
	if ( (f = fopen(filename, "r") ) == NULL ) {
		printf ("Unable to open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	else
		return f;
}

int main (void)
{
	FILE *file1, *file2;
	FILE *open (char filename[]);
	bool c1_read = true, c2_read = true;
	char filename1[64], filename2[64];
	char c1, c2;
	
	printf ("Enter file1 file2 : ");
	scanf ("%63s %63s", filename1, filename2);
	
	file1 = open(filename1);
	file2 = open(filename2);
	
	while (c1_read || c2_read) {
		while (c1_read) {
			c1 = getc(file1);
			if (c1 == EOF)
				c1_read = false;
			else {
				printf ("%c", c1);
				if (c1 == '\n')
					break;
			}
		}
		
		while (c2_read) {
			c2 = getc(file2);
			if (c2 == EOF)
				c2_read = false;
			else {
				printf ("%c", c2);
				if (c2 == '\n')
					break;
			}
		}
		
	}
	
	fclose(file1);
	fclose(file2);
	printf("\n");
	
	return 0;
}