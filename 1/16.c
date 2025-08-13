/* Exercise 1-16. Revise the main routine of the longest-line program so it will
correctly print the length of arbitrarily long input lines, and as much as possible
of the text.*/

#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = getLine(line, MAXLINE)) > 0) {
    if(len > max) {
      max = len;
      int i;
      for(i = 0; (longest[i] = line[i]) != '\0'; ++i)
        ;
    }
  }
  printf("%d\n", max);
  if(max > 0) {
    printf("%s", longest);
  }
  return 0;
}

int getLine(char s[], int lim) {
  int c, i = 0, len = 0;

  while((c = getchar()) != EOF && c != '\n') {
    if(i < lim - 1) {
      s[i++] = c;
    }
    ++len;
  }
  if(c == '\n') {
    ++len;
    if(i < lim -1) {
      s[i++] = '\n';
    }
  }
  s[i] = '\0';
  if(c == EOF && len == 0) {
    return 0;
  }
  return len;
}
