#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  printf("Celsius\tFahr\n");
  printf("--------------\n");
  while(celsius <= upper) {
    float fahr = (9.0/5.0) * celsius + 32.0;
    printf("%6.1f\t%3.0f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
