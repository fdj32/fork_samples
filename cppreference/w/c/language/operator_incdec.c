#include <stdlib.h>
#include <stdio.h>
 
int main(void) {
 
  int a = 1;
  int b = 1;
 
  printf("\n");
  printf("original values: a == %d, b == %d\n", a, b);
  printf("result of postfix operators: a++ == %d, b-- == %d\n", a++, b--);
  printf("after postfix operators applied: a == %d, b == %d\n", a, b);
 
  // Reset a and b.
  a = 1;
  b = 1;
 
  printf("\n");
  printf("original values: a == %d, b == %d\n", a, b);
  printf("result of prefix operators: ++a == %d, --b == %d\n", ++a, --b);
  printf("after prefix operators applied: a == %d, b == %d\n", a, b);
}