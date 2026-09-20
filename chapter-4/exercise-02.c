/*
 * Exercise 4-2. Extend atof to handle scientific notation of the form
 * 123.45e−6
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <_stdio.h>
#include <ctype.h>
#include <stdio.h>

#define MAXSTR 100

int main() {
  double sum, atof(char[]);
  int get_line(char s[], int t);
  char line[MAXSTR];

  sum = 0;

  while(get_line(line, MAXSTR) > 0) {
    printf("\t%g\n", sum += atof(line));
  }

  return 0;
}

double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++) {
    ;
  }

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;
  
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e') {
    i++;
    
    for(int sc = (s[++i] - '0'); sc > 0; sc--) {
      val /= 10.0;
    }
  }

  return sign * val / power;
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
