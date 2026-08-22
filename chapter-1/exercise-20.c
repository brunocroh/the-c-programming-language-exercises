/*
“Exercise 1-20. Write a program detab that replaces tabs in
the input with the proper number of blanks to space to the next tab stop.
Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?”

Excerpt From
The C Programming Language, Second Edition (for    )
Brian W. Kernighan
This material may be protected by copyright.
*/
#include <stdio.h>

#define TABSTOP 8

int main() {
  int p, c, nb;

  p = 1;
  while((c = getchar()) != EOF) {
    if (c == '\t') {
      nb = TABSTOP - ((p - 1) % TABSTOP);
      while(nb > 0) {
        putchar('.');
        p++;
        nb--;
      }
    } else {
      putchar(c);
      p++;
    }

    if (c == '\n') {
      p = 1;
    }
  }


  return 0;
}
