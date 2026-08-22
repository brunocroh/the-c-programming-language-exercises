/*
“Exercise 1-21. Write a program entab that replaces strings of blanks
by the minimum number of tabs and blanks to achieve the same spacing.
Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop,
which should be given preference?”

Excerpt From
The C Programming Language, Second Edition (for    )
Brian W. Kernighan
This material may be protected by copyright.
*/
#include <stdio.h>

#define TABSTOP 4

int main() {
  int c, nb;

  nb = 0;
  while((c = getchar()) != EOF) {
    if (c == ' ') {
      nb++;
    } else {
      while(nb > 0) {
        putchar(' ');
        nb--;
      }
      putchar(c);
    }


    if(nb == TABSTOP) {
      putchar('\t');
      nb = 0;
    }
  }

  return 0;
}
