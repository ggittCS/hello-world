// Program to print the number typed in into English

#include <stdio.h>

int main(void)
{
	int number, left_digit, divisor;
	
	printf("Please type in an integer.\n");
	scanf("%i", &number);
	
	if (number == 0)
		printf("zero");
	
	if (number<=99999999 && number>=-99999999) {
		
		if (number<0) {
			number=-number;
			printf("negative ");
		}
			
		for (divisor = 100000000; divisor != 1; divisor = divisor/10) {
			if (divisor <= number*10) {
				left_digit = (number % divisor) / (divisor/10);
				switch (left_digit)
				{
					case 1:
						printf("one ");
						break;
					case 2:
						printf("two ");
						break;
					case 3:
						printf("three ");
						break;
					case 4:
						printf("four ");
						break;
					case 5:
						printf("five ");
						break;
					case 6:
						printf("six ");
						break;
					case 7:
						printf("seven ");
						break;
					case 8:
						printf("eight ");
						break;
					case 9:
						printf("nine ");
						break;
					case 0:
						printf("zero ");
						break;
					default:
						printf("Unrecognized character");
						break;
						
				}
					
			}
		}
	}
	else
		printf("Number is out of range.\n");


return 0;
}