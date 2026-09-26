/*
 *
 * Exercise 4-9. Our getch and ungetch do not handle
 * a pushed-back EOF correctly. Decide what their properties
 * ought to be if an EOF is pushed back, then implement your design.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100

int buf_index;
int buf[BUFSIZE];

int getch(void);
void ungetch(int c);

int main() {
  int c;

  c = getch();
  putchar(c);

  ungetch(EOF);

  c = getch();

  if(c == EOF) {
    printf("EOF returned \n");
  } else {
    putchar(c);
  }

  return 0;
}

int getch(void) {
  return buf_index > 0 ? buf[--buf_index] : getchar();
}

void ungetch(int c) {
  if (buf_index >= BUFSIZE ){
    printf("ungetch: buffer is full\n");
  } else {
    buf[buf_index++] = c;
  }
}
