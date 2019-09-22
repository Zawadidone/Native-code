#include <stdio.h>

int main() {
  int n = 10;

  /* your code goes here */
  // initialize pointer that points to the memory address of n
  int * pointer_to_n = &n;

  // increments the value pointed to by the pointer pointer_to_no by 1
  (*pointer_to_n)++;

  /* testing code */
  if (pointer_to_n != &n)  return 1;
  if (*pointer_to_n != 11) return 1;

  printf("Done!\n");
  return 0;
}
