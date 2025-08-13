#include <stdio.h>

int main() {
  long nl = 0;

  while((c = getchar() != EOF) {
    if(c == '\n') {
      ++nl;
    }
  }
  printf("%ld\n", nl);
  return 0;
}

