/*
 * Exercise 2-5. Write the function any(s1,s2), which returns the first
 * location in the string s1 where any character from the string s2 occurs,
 * or −1 if s1 contains no characters from s2. (The standard library function
 * strpbrk does the same job but returns a pointer to the location.)
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>

#define MAXSTR 1000

int any(char s1[], char s2[]);
int get_line(char str[], int max);

int main() {
  char s1[MAXSTR], s2[MAXSTR];
  int len;

  while((len = get_line(s1, MAXSTR)) != 0) {
    get_line(s2, MAXSTR);
    printf("index of: %d\n", any(s1, s2));
  }

  return 0;
}

int any(char s1[], char s2[]) {
  int r = -1;

  for(int i = 0; r == -1 && s1[i] != '\0'; i++) {
    for (int j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        r = i;
        break;
      } 
    }
  }

  return r;
}

int get_line(char str[], int limit) {
  int i, c;

  i = 0;
  while((c = getchar()) != EOF && c != '\n') {
    str[i++] = c;
  }

  str[i] = '\0';

  return i;
}
