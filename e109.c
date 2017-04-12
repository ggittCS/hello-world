// Function to replace one string with another using previous functions

#include <stdio.h>
#include <stdbool.h>

int findString (const char str1[], const char str2[])
{
	int i, j;
	bool foundit = false;
	
	for (i=0; str1[i] != '\0' && foundit == false; ++i) {
		foundit = true;
		
		for (j=0; str2[j] != '\0' && foundit == true; ++j)
			if (str1[j + i] != str2[j] || str1[j + i] == '\0')
				foundit = false;
			
			if (foundit == true)
				return i;
	}
	
	return -1;
}

void removeString (char str[], int start, int length)
{
	int i;
	
	for (i = 0; i < start; ++i)
		if (str[i] == '\0')
			return;
		
	for (i ; i < start + length; ++i)
		if (str[i] == '\0') {
			str[start] = '\0';
			return;
		}
	
	do {
		str[i - length] = str[i];
	} while (str[i++] != '\0');

}

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

bool replaceString (char source[], char s1[], char s2[])
{
	int findLocation, length;
	int findString (const char str1[], const char str2[]);
	void removeString (char str[], int start, int length);
	void insertString (char source[], char s[], int i);
	int stringLength (const char string[]);
	
	findLocation = findString (source, s1);
	
	if (findLocation == -1)
		return false;
	
	length = stringLength(s1);
	
	removeString (source, findLocation, length);
	
	insertString (source, s2, findLocation);
	
	return true;
		
	
}

int main (void)
{
	bool replaceString (char source[], char s1[], char s2[]);
	char words[50] = {"Today is great!"};
	char remove[] = {"a"};
char replace[] = {"offfff"};
	bool stillFound = true;
	
	
	do {
		stillFound = replaceString (words, remove, replace);
	}
	while (stillFound == true);
	
	printf("%s", words);
	
	return 0;
}