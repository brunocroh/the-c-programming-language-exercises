/*
 * Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 100

int invert(unsigned int x, int p, int n);

int main() {
  char buffer[MAXSTR];
  printf("Insert a octal number: ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = 0;

  int input = (int)strtol(buffer, (char **)NULL, 8);
  printf("%o", invert(input, 5, 3));

  return 0;
}

int invert(unsigned int x, int p, int n) {
  int mask = ~(~0 << n) << (p+1-n);

  return x ^ mask;
}
