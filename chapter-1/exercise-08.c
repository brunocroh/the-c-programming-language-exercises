#include <stdio.h>

int main() {
  int c, nb, nt, nl;

  nb = nt = nl = 0;
  while((c = getchar()) != EOF) {
    if(c == ' ') {
      nb++;
    }
    if(c == '\t') {
      nt++;
    }
    if(c == '\n') {
      nl++;
    }
  }

  printf("blanks:%d\ttabs:%d\tnew lines:%d\n", nb, nt, nl);
  return 0;
}
