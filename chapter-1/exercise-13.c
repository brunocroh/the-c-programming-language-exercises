#include <stdio.h>

#define IN  1
#define OUT 0

int main() {

  int nwords[10], c, state, wlength;

  for (int i = 0; i < 10; i++) {
    nwords[i] = 0;
  }

  state = OUT;
  wlength = 0;
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        nwords[wlength]++;
        wlength = 0;
        state = OUT;
      } 
    } else {
      if (state == IN) {
        wlength++;
      } else {
        state = IN;
        wlength = 1;
      }
    }
  }

  if(wlength) {
    nwords[wlength]++;
  }

  printf("  1 2 3 4 5 6 7 8 9\n");
  for (int i = 1; i < 10; i++) {
    printf("%d", i);
    for (int j = 0; j < nwords[i]; j++) {
      printf("##");
    }
    printf("\n");
  };

  return 0;
}
