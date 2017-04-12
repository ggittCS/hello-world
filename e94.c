// Program to tell which day of the week it isalnum

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
	int n;
	struct date dateGiven;
	
	printf ("Give me a date (mm dd yyyy):\n");
	scanf ("%i %i %i", &dateGiven.month, &dateGiven.day, &dateGiven.year);
	
	
	n = (totalDays (dateGiven) - 621049) % 7;
	
	if (n == 0)
		printf ("The day of the week is Sunday\n");
	else if (n == 1)
		printf ("The day of the week is Monday\n");
	else if (n == 2)
		printf ("The day of the week is Tuesday\n");
	else if (n==3)
		printf ("The day of the week is Wednesday\n");
	else if (n==4)
		printf("The day of the week is Thursday\n");
	else if (n==5)
		printf ("The day of the week is Friday\n");
	else if (n == 6)
		printf("The day of the week is Saturday\n");
	

	return 0;
}