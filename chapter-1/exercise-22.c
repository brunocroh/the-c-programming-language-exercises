/*
“Exercise 1-22. Write a program to “fold” long input lines
into two or more shorter lines after the last non-blank character
that occurs before the n-th column of input.
Make sure your program does something intelligent with very long lines,
and if there are no blanks or tabs before the specified column.”

Excerpt From
The C Programming Language, Second Edition (for    )
Brian W. Kernighan
This material may be protected by copyright.
*/
#include <stdio.h>

#define FOLD_THRESHOLD 20

int main() {
  char word[100];
  int i, c, nc;

  nc = 0;
  for (i = 0; (c = getchar()) != EOF; i++) {
    if(c == '\n' || c == '\t' || c == ' ') {

      if(i > FOLD_THRESHOLD) {
        putchar('\n');
        i = nc;
      }

      if (nc > 0) {
        printf("%s", word);
        while(nc > 0) {
          word[nc--] = 0;
        }
        putchar(c);
      }
    } else {
      word[nc++] = c;
    }
  }

  if(nc > 0) {
    printf("%s", word);
  }

  return 0;
}
