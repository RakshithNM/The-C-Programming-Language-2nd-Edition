/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1000

int read_trim(char line[], int maxline);

int main() {
  int len;
  char line[MAXLINE];

  while((len = read_trim(line, MAXLINE)) != -1) {
    if(len > 0) {
      printf("%s", line);
    }
  }
  return 0;
}

int read_trim(char line[], int lim) {
  int c, i = 0;
  while((c = getchar()) != EOF && c != '\n') {
    if(i < lim - 1) {
      line[i++] = c;
    }
  }
  while(i > 0 && (line[i - 1] == ' ' || line[i - 1] == '\t')) {
    --i;
  }
  if(c == '\n' && i > 0 && i < lim - 1) {
    line[i++] = c;
  }
  line[i] = '\0';
  if(c == EOF && i == 0) {
    return -1;
  }
  return i;
}
