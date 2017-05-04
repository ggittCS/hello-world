// Program to reverse the digits of a number again

#include <stdio.h>

int main(void)
{
	int number, right_digit;
	
	printf("Enter your number.\n");
	scanf("%i", &number);
	
	if (number<0) {
		number=-number;
		do {
			right_digit = number % 10;
			printf("%i", right_digit);
			number = number/10;
		}
	
		while( number != 0);
	
		printf("-\n");
	}
	else {
		do {
			right_digit = number % 10;
			printf("%i", right_digit);
			number = number/10;
		}
	
		while( number != 0);
	}
	
	return 0;
}