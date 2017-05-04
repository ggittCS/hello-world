// Rewrite the compareStrings function to use character pointers

#include <stdio.h>

int compareStrings (const char *ptr, const char *ptr2)
{
	int  answer;
	
	while (*ptr == *ptr2 && *ptr != '\0' && *ptr2 != '\0') {
		++ptr;
		++ptr2;
	}
	
	
	if (*ptr < *ptr2)
		answer = -1;		/* s1 < s2 */
	else if (*ptr == *ptr2)
		answer = 0;		/* s1 == s2 */
	else
		answer = 1;		/* s1 > s2 */
	
	return answer;
}

int main (void)
{
	const char s1[] = "Apple";
	const char s2[] = "Aarrdvark";
	
	const char *ptr1 = s1;
	const char *ptr2 = s2;
	
	int i;
	
	i = compareStrings (ptr1, ptr2);
	
	printf ("%i", i);
	
	return 0;
}