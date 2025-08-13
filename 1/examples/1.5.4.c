#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, nc, nw, nl, state;

  state = OUT;
  nc = nw = nl = 0;
  while((c = getchar()) != EOF) {
    ++nc;
    if(c == '\n') {
      ++nl;
    }
    if(c == '\n' || c == '\t' || c == ' ') {
      state = OUT;
    } 
    else if(state == OUT) {
      ++nw;
      state = IN;
    }
  }
  printf("character count: %d\t word count: %d\t line count: %d\n", nc, nw, nl);
  return 0;
}

