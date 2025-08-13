/* Exercise 1-8. Write a program to count blanks, tabs, and newlines */
#include <stdio.h>

int main() {
  long nb = 0, nt = 0, nn = 0;
  int c;
  while((c = getchar()) != EOF) {
    if(c == ' ') {
      ++nb;
    }
    else if(c == '\t') {
      ++nt;
    }
    else if(c == '\n') {
      ++nn;
    }
  }
	printf("\nnb: %ld, nt: %ld, nn: %ld\n", nb, nt, nn);
  return 0;
}

