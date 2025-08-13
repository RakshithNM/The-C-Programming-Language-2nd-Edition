/* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */
#include <stdio.h>

float calculateCelsius(float fahrenheit);

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("%s\t%s\n", "Fahrenheit", "Celsius");
  fahr = lower;
  while(fahr <= upper) {
    celsius = calculateCelsius(fahr);
    printf("%10.1f\t%7.1f\n", fahr, celsius);
    fahr += step;
  }
  return 0;
}

float calculateCelsius(float fahrenheit) {
  return 5.0 * (fahrenheit - 32.0) / 9.0;
}
