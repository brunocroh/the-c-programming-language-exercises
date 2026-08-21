#include <stdio.h>

int to_celsius(int fahr);

int main() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while(fahr <= upper) {

    
    printf("%d\t%d\n", fahr, to_celsius(fahr));
    fahr = fahr + step;
  }

  return 0;
}

int to_celsius(int fahr) {
  return 5 * (fahr-32) / 9;
}
