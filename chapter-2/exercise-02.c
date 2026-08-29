/*
 * Exercise 2-2. Write a loop equivalent to the for loop above
 * without using && or ||.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>

#define LIMIT 1000

int main() {
  int i, c;
  char s[LIMIT];

  i = 0;
  while((c = getchar()) != EOF) {
    if(c == '\n') {
      break;
    }

    if(i >= LIMIT - 1) {
      break;
    }

    s[i++] = c;
  }

  s[i] = '\0';

  printf("%s", s);

  return 0;
}

