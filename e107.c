// Program to insert one character string into another string.

#include <stdio.h>

int stringLength (const char string[])
{
	int count = 0;
	
	while (string[count] != '\0')
		++ count;
	
	return count;
}

void insertString (char source[], char s[], int i)
{
	int j, lenS, lenSource;
	
	/* first, find out how big the two strings are */

	lenSource = stringLength (source);
	lenS = stringLength (s);
	
	/* sanit check here -- note that i == lenSource
		effectively concatenates s onto the end of source */
		
	if (i > lenSource)
		return;
	
	/* now we have to move the characters in source 
		down from the insertion point to make room for s.
		Note that we copy the string starting from the end
		to avoid overwriting characters in source.
		We also copy the terminating null (j starts at lenS)
		as well since the final result must be null-terminated */
		
	for (j = lenSource; j >= i; --j)
		source[lenS + j] = source[j];
	
	/* we've made room, now copy s into source at the insertion point */
	
	for (j = 0; j < lenS; ++j)
		source[j+i] = s[j];

}

int main (void)
{
	int j = 4;
	char string[] = {"Greg Gittinger"};
	char add[] = {"ory the Greatest Ever"};
	void insertString (char source[], char s[], int i);
	
	
	insertString (string, add, j);
	
	printf("%s", string);
	
	return 0;
}