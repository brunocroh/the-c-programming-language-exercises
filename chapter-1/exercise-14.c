#include <stdio.h>

#define OFFSET 'a'

int main() {

  int nwords[26], c, state, wlength;

  for (int i = 0; i < 26; i++) {
    nwords[i] = 0;
  }

  while((c = getchar()) != EOF) {
    nwords[c-OFFSET]++;
  }


  printf("  1 2 3 4 5 6 7 8 9\n");
  for (int i = 0; i < 26; i++) {
    if(nwords[i] == 0) continue;

    printf("%c", i+OFFSET);
    for (int j = 0; j < nwords[i]; j++) {
      printf("##");
    }
    printf("\n");
  };

  return 0;
}
