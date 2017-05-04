#include <stdio.h>

int main()
{
  int val;

  printf("blah %n blah\n", &val);

  printf("val = %d\n", val);

  return 0;

}