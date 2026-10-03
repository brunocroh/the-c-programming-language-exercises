/*
 *
 * Exercise 4-14. Define a macro swap(t,x,y) that interchanges
 * two arguments of type t. (Block structure will help.)
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>

#define swap(t, A, B) \
  {                   \
    t tmp;            \
    tmp = A;          \
    A = B;            \
    B = tmp;          \
  };

int main() {
  int a = 1;
  int b = 0;

  printf("a:%d b:%d\n",a,b);
  swap(int, a, b);
  printf("a:%d b:%d\n",a,b);

  printf("======\n");

  int c = 'A';
  int d = 'B';
  printf("c:%c d:%c\n",c,d);
  swap(char, c, d);
  printf("c:%c d:%c\n",c,d);

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
