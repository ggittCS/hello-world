// Introducing the #define statement

#include <stdio.h>

#define YES 1
#define NO 0

// Function to determine if an integer is even

int isEven (int number)
{
	int answer;
	
	if (number % 2 == 0)
		answer = YES;
	else
		answer = NO;
	
	return answer;
}

int main (void)
{
	int isEven (int number);
	
	if (isEven (17) == YES)
		printf ("YES ");
	else
		printf ("NO ");
	
	if (isEven (20) == YES)
		printf ("YES\n");
	else
		printf ("NO\n");
	
	return 0;
}