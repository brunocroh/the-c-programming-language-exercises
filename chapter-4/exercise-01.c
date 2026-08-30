/*
 * Exercise 4-1. Write the function strrindex(s,t), which returns the
 * position of the rightmost occurrence of t in s, or −1 if there is none.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>

#define MAXSTR 1000

int strrindex(char s[], char t[]);

int main() {
  char str[MAXSTR] = "Ah Love! could you and I with Fate conspire";
  char t[MAXSTR] = "ould";

  printf("index: %d\n", strrindex(str, t));
}


int strrindex(char s[], char t[]) {
  int j = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    while(s[i] == t[j]) {
      if(t[j+1] == '\0') {
        return i-j; 
      }

      i++;
      j++;
    }

    j = 0;
  }

  return -1;
}
