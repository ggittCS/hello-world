// Function to change lowercase characters in a string to uppercase

#include <stdio.h>

int stringLength (const char string[])
{
	int count = 0;
	
	while (string[count] != '\0')
		++ count;
	
	return count;
}

void uppercase (char string[])
{
	int i, length;
	
	length = stringLength(string);
	
	for (i=0; i<length; ++i)
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] = string[i] - 'a' + 'A';
	
}

int main (void)
{
	char words[] = "Today Is Awesome";
	
	uppercase (words);
	
	printf("%s", words);
	
	return 0;
}