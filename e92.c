// Program to tell time difference between two dates

#include <stdio.h>

struct date
{
	int month;
	int day;
	int year;
};

int totalDays (struct date d)
{
	int n;
	int f (struct date a);
	int g (struct date b);
	
	n = 1461 * f (d) / 4 + 153 * g (d) / 5 + d.day;
	
	return n;
}

int f (struct date a)
{
	int i;
	
	if (a.month <= 2)
		i = a.year - 1;
	else
		i = a.year;
	
	return i;
}

int g (struct date b)
{
	int i;
	
	if (b.month <= 2)
		i = b.month + 13;
	else
		i = b.month + 1;
	
	return i;
}

int main (void)
{
	int n1, n2, diffDays;
	struct date first, second;
	
	printf ("Give me the first date (mm dd yyyy):\n");
	scanf ("%i %i %i", &first.month, &first.day, &first.year);
	
	printf ("Give me the second date (mm dd yyyy):\n");
	scanf ("%i %i %i", &second.month, &second.day, &second.year);
	
	n1 = totalDays (first);
	n2 = totalDays (second);
	
	diffDays = n2 - n1;
	
	printf ("The difference in days is %i\n", diffDays);
	
	return 0;
}