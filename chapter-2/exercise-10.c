/*
 * Exercise 2-10. Rewrite the function lower, which converts upper case
 * letters to lower case, with a conditional expression instead of if-else.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <string.h>

#define MAXSTR 100

int lower(char str[]);

int main() {
  char buffer[MAXSTR];
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = 0;

  lower(buffer);
  printf("lowercase: %s", buffer);
  
  return 0;
}

int lower(char str[]) {
  int i;

  for(i = 0; str[i] != 0; i++) {
    str[i] = str[i] <= 'Z' && str[i] >= 'A' ? str[i] + 32 : str[i];
  }

  return i;
}
