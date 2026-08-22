/*
“Exercise 1-23. Write a program to remove all comments from a C program.
Don’t forget to handle quoted strings and character constants properly.
C comments do not nest.”

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
