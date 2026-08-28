#include <stdio.h>

#define MAXLINE 1000

int squeeze(char s[], char t[]);
int get_line(char s[], int limit);

int main() {
  int len;
  char str[MAXLINE], filter[MAXLINE];

  while((len = get_line(str, MAXLINE)) > 0) {
    get_line(filter, MAXLINE);
    squeeze(str, filter);

    printf("%s\n", str);
  }

  return 0;
}

int squeeze(char s[], char t[]) {
  int i, j, k;
  int eq;

  for(i = j = 0; s[i] != '\0'; i++) {
    eq = 0;
    for(k = 0; t[k] != '\0'; k++) {
      if(s[i] == t[k]) {
        eq = 1;
        break;
      }
    }

    if(eq == 0) {
      s[j++] = s[i];
    }
  }

  s[j] = '\0';

  return i;
}

int get_line(char s[], int limit) {
  int i, c;

  i = 0;
  while((c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}
