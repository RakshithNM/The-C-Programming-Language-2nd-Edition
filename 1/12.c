/* Exercise 1-12. Write a program that prints its input one word per line. */
#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  /* Method 1 */
  int c, state = OUT;
  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\t' || c == '\n') {
      if(state == IN) {
        putchar('\n');
        state = OUT;
      }
    }
    else {
      putchar(c);
      state = IN;
    }
  }

  /* Method 2 */
  int ch;
  while((ch = getchar()) != EOF) {
    if(ch == ' ') {
      putchar('\n');
    }
    else {
      putchar(ch);
    }
  }

  return 0;
}

