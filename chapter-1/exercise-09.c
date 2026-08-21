#include <stdio.h>

int main() {
  int c, prev;

  while((c = getchar()) != EOF) {
    if (c == ' ' && prev == c) continue;

    prev = c;
    putchar(c);
  }

  return 0;
}
