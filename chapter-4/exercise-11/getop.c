#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {
  int i, c, op;
  static int tmp = EOF;
  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c != '.') {
    if(c != '-') {
      return c;
    } else {
      op = c;
    }

  }

  if(c == '-') {
    if(isdigit(c = getch())) {
      tmp = c;
    } else {
      tmp = c;
      return op;
    }
  }

  i = 0;


  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }

  if (c == '.') {
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }

  s[i] = '\0';

  if (c != EOF) {
    tmp = c;
  }
  return NUMBER;
}
