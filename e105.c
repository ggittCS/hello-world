// Program to determine if one character string exists inside another string.

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

int main (void)
{
	int index;
	int findString (const char str1[], const char str2[]);
	
	index = findString ("operator", "rat");
	
	printf ("%i", index);
	
	return 0;
}