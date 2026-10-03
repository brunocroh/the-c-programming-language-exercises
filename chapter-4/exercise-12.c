/*
 *
 * Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer into a string
 * by calling a recursive routine.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>


void itoa(int n, char res[]);


int main() {
  char res[100];

  itoa(234, res);

  printf("result: %s", res);

  return 0;
}


void itoa(int n, char res[]) {
  static int i;

  if (n / 10) {
    itoa(n / 10, res);
  }

  res[i++] = n % 10 + '0';

  res[i] = '\0';
}
