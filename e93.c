// Program to calculate difference between two times

#include <stdio.h>

struct time
{
	int hour;
	int minute;
	int second;
};

struct time elapsed_time (struct time x, struct time y)
{
	struct time diff;
	
	diff.second = y.second - x.second;
	diff.minute = y. minute - x.minute;
	diff.hour = y.hour - x.hour;
	
	if (diff.second < 0) {
		diff.second += 60;
		diff.minute --;
	}
	
	if (diff.minute < 0) {
		diff.minute += 60;
		diff.hour --;
	}
	
	if (diff.hour < 0)
		diff.hour += 24;
	
	return diff;
}

int main (void)
{
	struct time time1, time2, timeDiff;
	struct time elapsed_time (struct time x, struct time y);
	
	printf ("Give me the first time (hh:mm:ss)\n");
	scanf ("%i:%i:%i", &time1.hour, &time1.minute, &time1.second);
	
	printf ("Give me the second time (hh:mm:ss)\n");
	scanf ("%i:%i:%i", &time2.hour, &time2.minute, &time2.second);
	
	timeDiff = elapsed_time (time1, time2);
	
	printf ("The elapsed time is %i hours, %i minutes, and %i seconds\n", timeDiff.hour,
		timeDiff.minute, timeDiff.second);
	
	return 0;
}