// Rewrite readLine function to use a character pointer

#include <stdio.h>

void readLine (char *buffer)
{
	char character;
	
	do
	{
		character = getchar ();
		*buffer++ = character;
	}
	while (character != '\n');
	
	*(buffer - 1) = '\0';
}

int main (void)
{
	char buffer[50];
	char *words = buffer;
	
	readLine (words);
	
	printf ("%s", buffer);
	
	return 0;
}