/*
 *
 * Exercise 4-8. Suppose that there will never be more than one character of pushback.
 * Modify getch and ungetch accordingly.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int buf = -1;

int getch(void);
void ungetch(int c);

int main() {
  char c;

  c = getch();
  printf("c: %c\n", c);

  ungetch(c);
  printf("%c\n", c = getch());

  return 0; 
}

int getch(void) {
  int tmp;

  if (buf != -1) {
    tmp = buf;
    buf = -1;

    return tmp;
  }

  return getchar();
}

void ungetch(int c) {
  if(buf != -1) {
    printf("ungetch: buffer full \n");
  } else {
    buf = c;
  }
}
