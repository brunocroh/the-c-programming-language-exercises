/*
 * Exercise 2-9. In a two's complement number system, x &= (x−1) deletes
 * the rightmost 1-bit in x. Explain why. Use this observation to write
 * a faster version of bitcount.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 100

int bitcount(unsigned int x);

int main() {
  char buffer[MAXSTR];
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = 0;

  int input = (int)strtol(buffer, (char **)NULL, 10);

  printf("number of bits: %d", bitcount(input));
  
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

int bitcount(unsigned int x) {
  int b;

  for(b = 0; x != 0; x &= (x-1)) {
    b++;
  }

  return b;
}
