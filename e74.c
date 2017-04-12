// Program that calculates the average of an array of 10 floating point values

#include <stdio.h>

int main (void)
{
	float values[10], average, sum=0;
	int i;
	
	printf("Give me 10 numbers and I will average them!\n");
	
	for (i=0; i<10; i++) {
		scanf ("%f", &values[i]);
		sum = sum + values[i];
	}
	
	average = sum/10;
	
	printf("The average is %f\n", average);
	
	return 0;
}