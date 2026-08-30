/*
 * Exercise 3-3. Write a function expand(s1,s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2. Allow for letters of either case and digits, and be
 * prepared to handle cases like a-b-c and a-z0−9 and -a-z. Arrange that
 * a leading or trailing - is taken literally.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXSTR 1000

int expand(char s1[], char s2[]);

int main() {
  char s2[MAXSTR];
  char *s1 = "a-z";

  expand(s1, s2);
  printf("%s\n", s2);

  return 0;
}

int expand(char s1[], char s2[]) {
  int i,j;

  j = 0;
  for (i = 0, j = 0; s1[i] != '\0'; i++) {
    if(s1[i] != '-') {
      s2[j++] = s1[i];
      continue;
    };
    char prev, after, curr;
    prev = curr = s1[i-1];
    after = s1[i+1];

    if(prev>after) continue;

    while(curr < after-1) {
      s2[j++] = ++curr;
    }
  }

  s2[j++] = '\0';

  return j;
}
