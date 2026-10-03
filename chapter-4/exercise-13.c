/*
 *
 * Exercise 4-13. Write a recursive version of the function reverse(s),
 * which reverses the string s in place.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>


void reverse(char res[]);


int main() {
  char str[100] = "String to be reversed";


  printf("str: %s\n", str);
  reverse(str);
  printf("result: %s\n", str);

  return 0;
}


void reverse(char str[]) {
  static int i = 0;
  static int j = 0;

  if(str[i] != '\0') {
    char c = str[i++];
    reverse(str);

    str[j++] = c;
  }

  if(str[j] == '\0') {
    i = 0;
    j = 0;
  }
}
