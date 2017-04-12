// Function to convert and integer into a string

#include <stdio.h>

void intToStr (int x, char string[])
{
	int i = 0, rem, len = 0, n;
	
	n = x; 
	
	
	while (n != 0) {
		len ++;
		n /= 10;
	}
	
	if (x>=0) {
		for (i=0 ; i < len; ++i) {
		rem = x % 10;
		x = x / 10;
		string[len - (i+1)] = rem + '0';
		}
	
	string[len] = '\0';
	}
	
	if (x < 0) {
		string[0] = '-';
		x = -x;
		
		for (i=0 ; i < len; ++i) {
			rem = x % 10;
			x = x / 10;
			string[len - (i)] = rem + '0';
		}
	
		string[len + 1] = '\0';
	}
	
}

int main (void)
{
	char string[50];
	int x = 11234, y = -134, z = 1987;
	
	intToStr(x, string);
	
	printf ("%s\n", string);
	
	intToStr(y, string);
	
	printf ("%s\n", string);
	
	intToStr(z, string);

	printf ("%s\n", string);
		
	return 0;
}

