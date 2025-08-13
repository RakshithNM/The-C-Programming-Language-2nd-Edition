/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */
#include <stdio.h>
#define LIMIT 1000

int isGreaterThan80(int len);
int getLineLength(char line[], int lim);

int main() {
  char line[LIMIT];
  int len = 0;

  while((len = getLineLength(line, LIMIT)) > 0) {
    if(isGreaterThan80(len)) {
      printf("%s", line);
    }
  }
  return 0;
}

int getLineLength(char line[], int lim) {
  int c, i = 0, stored = 0;
  while((c = getchar()) != EOF && c != '\n') {
    if(stored < lim - 1) {
      line[stored++] = c;
    }
    ++i;
  }
  if(c == '\n') {
    if(stored < lim - 1) {
      line[stored++] = c;
    }
    ++i;
  }
  if(stored > lim - 1) {
    stored = lim - 1;
  }
  line[stored] = '\0';
  if(c == EOF && i == 0) {
    return 0;
  }
  return i;
}

int isGreaterThan80(int len) {
  if(len > 80) {
    return 1;
  }
  return 0;
}
