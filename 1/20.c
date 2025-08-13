/* Exercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic parameter? */
#define TABSTOPLENGTH 8

#include <stdio.h>

int main() {
  int c, i;
  int cur = 0;
  while((c = getchar()) != EOF) {
    if(c == '\n') {
      putchar(c);
      cur = 0;
    }
    if(c == '\t') {
      for(i = 0; i < (TABSTOPLENGTH - (cur % TABSTOPLENGTH)); i++) {
        putchar(' ');
      }
      cur = 0;
    }
    else {
      putchar(c);
      cur++;

      if(cur >= TABSTOPLENGTH) {
        cur = 0;
      }
    }
  }
  return 0;
}
