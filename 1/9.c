/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
#include <stdio.h>

int main() {
  int c;
  int blankPrinted = 0;

  while((c = getchar()) != EOF) {
    if(c == ' ') {
      if(blankPrinted == 0) {
        putchar(c);
        blankPrinted = 1;
      }
    }
    else {
      putchar(c);
      blankPrinted = 0;
    }
  }
  return 0;
}

