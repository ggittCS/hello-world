// A type that represents a pointer to a function that returns an int and that takes no arguments

#include <stdio.h>

typedef int (*FunctionPtr) (void);

int testFunction (void)
{
	return 1;
}

int main (void)
{
	int testFunction (void);
	FunctionPtr testFcPtr;
	
	testFcPtr = testFunction;
	
	printf ("%i\n", testFcPtr() );
	
	return 0;
}