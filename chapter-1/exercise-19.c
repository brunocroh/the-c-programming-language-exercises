#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max);
void reverse(char line[], int length);

int main() {
  char line[MAXLINE];
  int len;

  while((len = get_line(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }

  return 0;
}

int get_line(char line[], int max) {
  int i, c;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = '\n';
    i++;
  }

  line[i] = '\0';

  return i;
}

void reverse(char line[], int len) {
  int lo, aux;

  if(line[len] == '\0') {
    len--;
  }

  if(line[len] == '\n') {
    len--;
  }

  lo = 0;
  while(lo < len) {
    aux = line[len];
    line[len] = line[lo];
    line[lo] = aux;

    len--;
    lo++;
  }
}
