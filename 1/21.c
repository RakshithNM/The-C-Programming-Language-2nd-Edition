/* Exercise 1-21. Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the
same tab stops as for detab. When either a tab or a single blank would suffice
to reach a tab stop, which should be given preference? */
#define TABSTOPLENGTH 8

#include <stdio.h>

int getSpacesToStop(int col);
void flushSpaces(int *pendingSpaces, int absorbRemainder);

void flushSpaces(int *pendingSpaces, int absorbRemainder) {
  if(*pendingSpaces < 0) {
    return;
  }
  if(!absorbRemainder) {
    for(int i = 0; i < *pendingSpaces; i++) {
      putchar('_');
    }
  }
  *pendingSpaces = 0;
}

int getSpacesToStop(int col) {
  int nextStop = ((col / TABSTOPLENGTH) * TABSTOPLENGTH) + TABSTOPLENGTH;
  return nextStop - col;
}

int main() {
  int c;
  int col = 0, pendingSpaces = 0;
  while((c = getchar()) != EOF) {
    if(c == ' ') {
      col++;
      pendingSpaces++;
      if((col % TABSTOPLENGTH) == 0 && pendingSpaces > 0) {
        putchar('|');
        pendingSpaces = 0;
      }
    }
    else if(c == '\t') {
      flushSpaces(&pendingSpaces, 1);
      putchar('|');
      col += getSpacesToStop(col);
    }
    else if(c == '\n') {
      flushSpaces(&pendingSpaces, 0);
      putchar(c);
      col = 0;
    }
    else {
      flushSpaces(&pendingSpaces, 0);
      putchar(c);
      col++;
    }
  }
  return 0;
}
