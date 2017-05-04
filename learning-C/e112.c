// Function to insert a new entry into a linked list.

#include <stdio.h>

struct entry
{
	int value;
	struct entry *next;
};

void insertEntry (struct entry *insert, struct entry *after)
{
	insert->next = after->next;
	after->next = insert;
}

int main (void)
{
	
	struct entry n1, n2, n3, n4;
	struct entry *list_pointer = &n1;
	struct entry *insert = &n4;
	
	
	n1.value = 100;
	n1.next = &n2;
	
	n2.value = 200;
	n2.next = &n3;
	
	n3.value = 300;
	n3.next = (struct entry *) 0; // Mark list end with null pointer
	
	n4.value = 250;
	
	insertEntry (insert, &n2);
	
	while (list_pointer != (struct entry *) 0 ) {
		printf("%i\n", list_pointer -> value);
		list_pointer = list_pointer->next;
	}
	
	return 0;
}
