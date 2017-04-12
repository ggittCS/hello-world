// remove an entry from an existing linked list
#include <stdio.h>
// linked list structure
struct entry
{
  int value;
  struct entry *next;
};
void removeEntry(struct entry *afterThis)
{
  // is this really the way it should be done?
  struct entry *list_pointer;
  list_pointer = afterThis; 
  list_pointer = list_pointer->next;
  afterThis->next = list_pointer->next;
  // this works though 
}
int main(void)
{
  // declarations
  struct entry n1, n2, n3, e1, start_list;
  struct entry *list_pointer = &start_list;
  struct entry *remove = &n1; //remove entry after n1 (n2)
  
  start_list.value = 0;
  start_list.next = &n1;
  
  n1.value = 10;
  n1.next = &n2;
  
  n2.value = 20;
  n2.next = &n3;
  
  n3.value = 30;
  n3.next = (struct entry *) 0; // maybe just a '0'?
  
  e1.value = 100;
  e1.next = (struct entry *) 0;
  
  removeEntry(remove);
  
  // lets print the results and see what happened
  while ( list_pointer != (struct entry *) 0 )
  {
    printf("value: %i\n", list_pointer->value);
    list_pointer = list_pointer->next;
  }
  
  return 0;
}