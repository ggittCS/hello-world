// Program to keep time and date combined

#include <stdio.h>
#include <stdbool.h>

struct date
{
	int month;
	int day;
	int year;
};

struct time
{
	int hour;
	int minute;
	int second;
};

struct dateAndTime
{
	struct date sdate;
	struct time stime;
};

struct dateAndTime clockKeeper (struct dateAndTime x)
{
	struct dateAndTime new;
	struct time timeUpdate (struct time now);
	struct date dateUpdate (struct date today);
	
	new.stime = timeUpdate (x.stime);
	
	if (new.stime.hour == 0) {
		if (new.stime.minute ==0) {
			if (new.stime.second == 0)
				new.sdate = dateUpdate (x.sdate);
		}
	}
	else
		new.sdate = x.sdate;
	
	
	return new;
}


// Function to update the time by one second

struct time timeUpdate (struct time now)
{
	++now.second;
	
	if (now.second == 60) {		// next minute
		now.second = 0;
		++now.minute;
		
		if (now.minute == 60) {	// next hour
			now.minute = 0;
			++now.hour;
			
			if (now.hour == 24)		// midnight
				now.hour = 0;
		}
	}
	
	return now;
}

// Function to calculate tomorrow's date

struct date dateUpdate (struct date today)
{
	struct date tomorrow;
	int numberOfDays (struct date d);
	
	if (today.day != numberOfDays (today)) {
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}
	else if (today.month == 12) {		// end of year
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else {											// end of month
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}
	
	return tomorrow;
}

// Function to find the number of days in a month

int numberOfDays (struct date d)
{
	int days;
	bool isLeapYear (struct date d);
	const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (isLeapYear && d.month==2)
		days=29;
	else
		days = daysPerMonth[d.month -1];
	
	return days;
}

// Function to determine if it's a leap year

bool isLeapYear (struct date d)
{
	bool leapYearFlag;
	
	if ((d.year % 4 ==0 && d.year % 100 !=0) || d.year % 400 ==0)
		leapYearFlag = true;		// It's a leap year
	else
		leapYearFlag = false; 	// Not a leap year
	
	return leapYearFlag;
}

int main (void)
{
	struct dateAndTime event, new;
	struct dateAndTime clockKeeper (struct dateAndTime x);
	
	printf ("Give me a date (mm dd yyyy)\n");
	scanf ("%i %i %i", &event.sdate.month, &event.sdate.day, &event.sdate.year);
	
	printf ("Give me a time (hh:mm:ss)\n");
	scanf ("%i:%i:%i", &event.stime.hour, &event.stime.minute, &event.stime.second);
	
	new = clockKeeper (event);
	
	printf ("The date and time is %i/%i/%i and %i:%i:%i\n", new.sdate.month, 
			new.sdate.day, new.sdate.year, new.stime.hour, 
			new.stime.minute, new.stime.second);
			
	return 0;
}