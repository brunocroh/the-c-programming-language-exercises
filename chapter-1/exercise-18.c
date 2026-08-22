#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max);
int remove_trailing_blanks_tabs(char line[], int length);
void debug(char line[]);

int main() {
  int len;
  char line[MAXLINE];

  while((len = get_line(line, MAXLINE)) > 0) {
    remove_trailing_blanks_tabs(line, len);
    if(len > 1) {
      // debug(line);
      printf("%s", line);
    }
  }

  return 0;
}

int get_line(char line[], int max) {
  int i, c;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++){
    line[i] = c;
  }

  if(c == '\n') {
    line[i] = '\n';
    i++;
  }

  line[i] = '\0';

  return i;
}

int remove_trailing_blanks_tabs(char line[], int length) {
  int c;

  while ((c = line[length-1]) ==  '\0' || c == '\n' || c == ' ' || c == '\t') {
    length--;
  }

  line[length] = '\0';

  return length;
}

void debug(char line[]) {
  int i, c;
  for (i = 0; (c = line[i]) != '\0'; i++) {

    if(c == ' ' || c == '\t') {
      line[i] = '.';
    }
  }
}
