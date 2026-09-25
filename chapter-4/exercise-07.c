/*
 *
 * Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
 * Should ungets know about buf and bufp, or should it just use ungetch?
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100
#define STRLIMIT 100

char buf[BUFSIZE];
int bufp = 0;

int getstr(char s[], int limit);
int getch(void);
void ungetch(int);
void ungetstr(char s[]);

int main() {
  char line[STRLIMIT];
  char temp[STRLIMIT];

  getstr(line, BUFSIZE);
  printf("before: %s", line);

  ungetstr(line);

  getstr(temp, BUFSIZE);
  printf("after: %s", temp);
}

int getstr(char s[], int limit) {
  int i, c;

  i = 0;
  while((c = getch()) != EOF && c != '\n') {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}

void ungetstr(char line[]) {
  int i = strlen(line);

  while(i) {
    ungetch(line[--i]);
  }
}

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
