// Exercise 2 of chapter 5, displaying n and n^2

#include <stdio.h>

int main(void)
{
	int n, m;
	
	printf("TABLE OF N and N^2 VALUES\n\n");
	printf("n		n^2\n");
	printf("-		---\n");
	
	for(n=1; n<=10; n++){
		m=n*n;
		printf("%i		%i\n", n, m);
	}
	
	
	return 0;
}