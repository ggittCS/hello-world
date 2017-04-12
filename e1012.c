// Function to convert a string to a floating point value

#include <stdio.h>
#include <stdbool.h>

int stringLength (const char string[])
{
	int count = 0;
	
	while (string[count] != '\0')
		++ count;
	
	return count;
}

float strToInt (const char string[])
{
	int i = 0, intValue, result = 0, pointLoc = 0, x = 0;
	float decResult = 0.0, decValue = 0, y = 1.0, floatDec, floatTotal;
	bool negative = false;
	int length;
	
	length = stringLength(string);
	
	if (string[0] == '-') {
		negative = true;
		i = 1;
	}
	
	for (i ; i <= length; ++i) 
		if (string[i] == '.') {
			pointLoc = i;
			break;
		}
	
	for (i = 0; i < length; ++i) {
		if (i < pointLoc) {
			intValue = string[i] - '0';
			result = result * 10 + intValue;
		}
		else if (i == pointLoc)
			continue;
		else {
			decValue = string[i] - '0';
			decResult = decResult * 10 + decValue;
			++x;
		}
	}
	
	for (i=1; i <= x; ++i)
		y = y*10;
	
	floatDec = decResult / y;
	
	floatTotal = result + floatDec;
	
	if (negative)
		floatTotal = -floatTotal;
	
	return floatTotal;
}

int main (void)
{
	float strToInt (const char string[]);
	
	printf ("%f\n", strToInt ("245.36798"));
	printf ("%f\n", strToInt ("100.125") + 25.0);
	printf ("%f\n", strToInt ("135.9"));
	
	return 0;
}