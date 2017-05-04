// Program to remove a specified number of characters from a string.

#include <stdio.h>

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

int main (void)
{
	int start = 4;
	int length = 3;
	char name[] = {"Gregory Gittinger"};
	
	removeString (name, start, length);
	
	printf("%s", name);
	
	return 0;
}