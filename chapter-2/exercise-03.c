/*
 * Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and
 * A through F.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

int htoi(char *s);
int poww(int b, int x);
int get_line(char *str, int max);

int main() {
  char str[MAXLINE];
  int len;
  while((len = get_line(str, MAXLINE)) != EOF) {
    printf("value: %d\n", htoi(str));
  }
  return 0;
}

int htoi(char *s) {
  int len, res, i, d;

  i = len = res = 0;

  while (s[i] != '\0') {
    i++;
  }
  len = i-1;
  
  i = 0;
  d = 0;

  while(s[i] != '\0') {
    if(s[i] == '0' && s[i+1] == 'x') {
      i += 2;
      len -= 2;
    }

    if (isdigit(s[i])) {
      d = s[i] - '0';
    } else {
      d = s[i] - 'W';
    }


    res += d * poww(16, len);

    len--;
    i++;
  }

  return res;
}

int poww(int b, int x) {
  int r = 1;

  while(x-- > 0) {
    r *= b;
  }

  return r;
}

int get_line(char str[], int max) {
  int c, i;

  i = 0;
  while((c = getchar()) != EOF && c != '\n') {
    str[i++] = c;
  }

  str[i] = '\0';
  return i;
}
