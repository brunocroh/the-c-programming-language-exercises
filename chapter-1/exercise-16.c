#include <stdio.h>

#define MAXLINE 6

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len, max;
  char line[MAXLINE], longest[MAXLINE];

  max = 0;

  while((len = get_line(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }

  }
  if(max > 0) {
    printf("%s", longest);
  }

  return 0;
}

int get_line(char line[], int maxline) {
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < maxline) {
      line[i] = c;
    }
  }

  if(c == '\n') {
    if (i >= maxline) {
      line[maxline-1] = c;
      i++;
    } else {
      line[i] = c;
      i++;
    }
  }

  if(i >= maxline) {
    line[maxline-1] = '\0';
  }
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;
  while((to[i] = from[i]) != '\0' ) {
    i++;
  }
}
