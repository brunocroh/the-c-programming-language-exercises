/*
 * Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving
 * the other bits unchanged.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 1000

int setbits(unsigned int x, int p, int n, int y);
int getbits(unsigned int x, int p, int n);

int main() {
  char buffer[MAXSTR];

  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
  int input = (int)strtol(buffer, (char **)NULL, 8);

  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
  int input2 = (int)strtol(buffer, (char **)NULL, 8);

  printf("result: %o\n", setbits(input, 5, 3, input2));

  return 0;
}

int setbits(unsigned int x, int p, int n, int y){
  int mask = ~0 << n;

  y = y & mask;
  x = (x >> (p+1-n)) & (~mask);

  printf("\n%o : %o\n", y, x);

  return y | x;
}
