/*
 * Exercise 3-5. Write the function itob(n,s,b)
 * that converts the integer n into a base b character
 * representation in the string s. In particular, itob(n,s,16)
 * formats n as a hexadecimal integer in s.”
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <string.h>

#define MAXSTR 1000

void itob(int n, char s[], int b);
void reverse(char s[]);
char digits[] = "0123456789ABCDEF";

int main() {
  int wordsize = sizeof(int) * 8;
  char s[MAXSTR];
  int n = 123;

  itob(n, s, 16);
  printf("number: %s\n", s);

  return 0;
}

void itob(int n, char s[], int b) {
  int i, sign;

  if ((sign = n) > 0) {
    n = -n;
  }

  i = 0;

  do {
    s[i++] = digits[(n % b) * -1];
  } while((n /= b) != 0);
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
