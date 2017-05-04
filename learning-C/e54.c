//Program to print factorials

#include <stdio.h>

int main(void)
{
	int n, factorial, count;
	
	printf("n		n!\n");
	printf("-		--\n");
	
	factorial = 1;
	
	
	for(n=1; n<=10; n++){
		factorial= n*factorial;		
		printf("%i		%i\n", n, factorial);
	}
	
	
	
	return 0;
}