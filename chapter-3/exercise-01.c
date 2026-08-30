/*
 * Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with
 * only one test inside the loop and measure the difference in run-time.
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int i = 0;
  int v[10];

  while(i < 10) {
    v[i] = i;
    i++;
  }

  printf("%d\n", binsearch(7, v, 10));
}


int binsearch(int x, int v[], int n) {
  int lo, mid, hi;

  lo = 0;
  hi = n -1;
  mid = (lo+hi) / 2;

  while(lo <= hi && v[mid] != x) {
    if(x < v[mid]) {
      hi = mid+1;
    } else {
      lo = mid-1;
    }

    mid = (lo+hi) / 2;
  }

  return v[mid] == x ? mid : -1;
}
