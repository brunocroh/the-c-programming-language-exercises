/*
 * Exercise 3-6. Write a version of itoa that accepts
 * three arguments instead of two.
 * The third argument is a minimum field width;
 * the converted number must be padded with blanks on
 * the left if necessary to make it wide enough.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <string.h>

#define MAXSTR 1000

void itoa(int n, char s[], int p);
void reverse(char s[]);

int main() {
  int wordsize = sizeof(int) * 8;
  char s[MAXSTR];
  int n = 1234567;

  itoa(n, s, 8);
  printf("%s", s);

  return 0;
}

void itoa(int n, char s[], int b) {
  int i, sign;

  if ((sign = n) > 0) {
    n = -n;
  }

  i = 0;

  do {
    s[i++] = '0' - n % 10;
  } while((n /= 10) != 0);

  while(i < b) {
    s[i++] = '0';
  }

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
