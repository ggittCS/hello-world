// Program to extract a portion of a character string.

#include <stdio.h>


int main (void)
{
	void substring (const char source[], int start, int count, char result[]);
	const char source[50];
	int start, count, i;
	char result[50];
	
	printf ("Give me a character string: \n");
	scanf ("%s", source);
	
	printf ("Tell me what character to start at \n");
	scanf ("%i", &start);
	
	printf ("Tell me how many characters to include\n");
	scanf ("%i", &count);
	
	for (i = 0; i < count && source[start + i] != '\0'; ++i)
		result [i] = source[start + i];
		
	result[i] = '\0';
	
	printf ("Your specified substring is: %s\n", result);
	
	return 0;
}