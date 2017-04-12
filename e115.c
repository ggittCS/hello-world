// Doubly linked list

#include <stdio.h>

struct entry
{
	int value;
	struct entry *next;
	struct entry *prev;
};

int main (void)
{
	struct entry n1, n2, n3, *firstPtr;
	int i;
	
	n1.value = 100;
	n2.value = 200;
	n3.value = 300;
	
	n1.next = &n2;
	n2.next = &n3;
	n3.next = (struct entry *) 0;
	
	n1.prev = (struct entry *) 0;
	n2.prev = &n1;
	n3.prev = &n2;
	
	//forward search through list
	
	firstPtr = &n1;
	
	while ( firstPtr != 0) {
		printf ("%i ", firstPtr->value);
		firstPtr = firstPtr->next;
	}
	
	printf ("\n");
	
	//backward search through list
	
	firstPtr = &n3;
	
	while (firstPtr != 0) {
		printf ("%i ", firstPtr->value);
		firstPtr = firstPtr->prev;
	}
	
	printf ("\n");
	
	return 0;
}