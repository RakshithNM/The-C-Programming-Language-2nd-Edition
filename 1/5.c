/* Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0. */
#include <stdio.h>

int main() {
  float celsius, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

	printf("%s\t%s\n", "Celsius", "Fahrenheit");

  celsius = upper;
  while(celsius >= lower) {
    fahr = celsius * (9.0 / 5.0) + 32.0;
    printf("%6.1f\t%10.1f\n", celsius, fahr);
    celsius -= step;
  }
  return 0;
}


