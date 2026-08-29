/*
 * Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 100

int rightrot(unsigned int x, int n);
void print_b(unsigned int x);

int main() {
  char buffer[MAXSTR];
  printf("Insert a octal number: ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = 0;

  int input = (int)strtol(buffer, (char **)NULL, 8);
  
  printf("\n");
  print_b(input);
  printf("-----------");
  print_b(rightrot(input, 5));

  return 0;
}

void print_b(unsigned int b) {
  size_t size = sizeof(b) * 8; 
  printf("\n");
  for(int i = size-1; i >= 0; --i) {
    printf("%d", (b >> i) & 1);
    if((i) % 8 == 0) printf(" ");
  }
  printf("\n");
}


int rightrot(unsigned int x, int n) {
  int shift = sizeof(x) * 8 - n;
  unsigned int mask = (1u << n) - 1;

  unsigned flip = x & mask;


  return (x >> n) | (flip << shift);
}
