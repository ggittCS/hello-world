// Exercise 11 of chapter 5- program that calculates the sum of digits of an integer

#include <stdio.h>

int main (void)
{
	int number, right_digit, sum;
	
	printf("Give me a number.\n");
	scanf("%i", &number);
	
	sum=0;
	
	while(number!=0){
		right_digit= number % 10;
		number= number/10;
		sum+=right_digit;
	}
	
	printf("The sum of each digit is %i\n", sum);
	
	return 0;
}