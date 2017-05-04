// Program to print 20 lines at a time and then stop if the letter 'q' is used.

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

int main(void)
{
	FILE *open(char filename[]);
	FILE *f;
	char filename[64];
	char c,input[2];
	int i, linecount = 0;
	
	printf("Filename : ");
	scanf("%63s",filename);
	f = open(filename);
	
	while((c = getc(f)) != EOF)
	{
		if (c == '\n')
			linecount++;
		if (linecount == 20)
		{
			linecount = 0;
			printf(":");
		        scanf("%1s", input) ;
			if (input[0] == 'q' || input[0] == 'Q')
			{
				fclose(f);
				return 0;
			}
		}
		printf("%c",c);
	}
	printf("\n");	
	fclose(f);
	return 0;
}