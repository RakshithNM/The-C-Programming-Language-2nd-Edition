/* Exercise 1-3. Modify the temperature conversion program to print a heading above the table. */
#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("%s\t%s\n", "Fahrenheit", "Celsius");
  fahr = lower;
  while(fahr <= upper) {
    celsius = 5.0 * (fahr - 32.0) / 9.0;
    printf("%10.1f\t%7.1f\n", fahr, celsius);
    fahr += step;
  }
  return 0;
}
