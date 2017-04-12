// Function to remove a new entry into a linked list.

#include <stdio.h>

struct entry
{
	int value;
	struct entry *next;
};

void removeEntry (struct entry *remove)
{
	remove->next = remove->next->next;
	
}

int main (void)
{
	
	struct entry n1, n2, n3, listHead;
	struct entry *list_pointer = &n1;
	struct entry *remove = &n1;  // removes the next one
	
	
	n1.value = 100;
	n1.next = &n2;
	
	n2.value = 200;
	n2.next = &n3;
	
	n3.value = 300;
	n3.next = (struct entry *) 0; // Mark list end with null pointer
	
	
	listHead.next = &n1;
	
	removeEntry (remove);
	
	while (list_pointer != (struct entry *) 0 ) {
		printf("%i\n", list_pointer -> value);
		list_pointer = list_pointer->next;
	}
	
	return 0;
}
