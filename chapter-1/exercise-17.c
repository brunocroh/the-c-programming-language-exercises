#include <stdio.h>

#define MAXLINE 1000
#define THRESHOLD 80

int get_line(char line[], int max);

int main() {
  char line[MAXLINE];
  int i, len;

  len = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if(len > THRESHOLD) {
      printf("%s\n",line);
    }
  }

  return 0;
}

int get_line(char line[], int max) {
  int i, c;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }

  if(c == '\n') {
    line[i] = '\n';
    i++;
  }

  line[i] = '\0';
  return i;
}
