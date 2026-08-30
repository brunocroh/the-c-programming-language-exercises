/*
 * Exercise 3-2. Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies
 * the string t to s. Use a switch. Write a function for the other direction
 * as well, converting escape sequences into the real characters.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <string.h>

#define MAXSTR 1000

int escape(char s[], char t[]);

int main() {
  char s2[MAXSTR];
  char *s1 = "teste\tteste\t\ntest\0";

  
  escape(s2, s1);
  printf("%s\n", s2);

  return 0;
}


int escape(char s[], char t[]) {
  int i, j;
  for(j = i = 0; t[i] != '\0'; i++) {
    switch(t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      default:
        s[j++] = t[i];
    }
  }

  s[j] = '\0';

  return j;
}
