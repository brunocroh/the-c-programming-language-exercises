/*
 * Exercise 2-4. In a two’s complement number representation,
 * our version of itoa does not handle the largest negative number,
 * that is, the value of n equal to −(2wordsize−1).
 * Explain why not. Modify it to print that value correctly,
 * regardless of the machine on which it runs.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <string.h>

#define MAXSTR 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
  int wordsize = sizeof(int) * 8;
  char s[MAXSTR];
  int n = -(1 << (wordsize - 1));

  itoa(n, s);
  printf("number: %s\n", s);

  return 0;
}

void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) > 0) {
    n = -n;
  }

  i = 0;

  do {
    s[i++] = '0' - n % 10;
  } while((n /= 10) != 0);
  if(sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int lo, hi, swp;
  lo = 0;
  hi = strlen(s)-1;

  while (lo < hi) {
    swp = s[hi];
    s[hi] = s[lo];
    s[lo] = swp;

    lo++;
    hi--;
  }
}
