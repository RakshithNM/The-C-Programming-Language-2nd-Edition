#include <stdio.h>

int main() {
  long length = 0;
  int c;
  while((c = getchar()) != '\n' && c != EOF) {
    ++length;
  }
  printf("%ld\n", length);
  return 0;
}

