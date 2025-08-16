/* Exercise 1-22. Write a program to "fold" long input lines into two or more
shorter lines after the last non-blank character that occurs before the n-th
column of input. Make sure your program does something intelligent with very
long lines, and if there are no blanks or tabs before the specified column */
#define N 5
#define LIMIT 1000

#include <stdio.h>

int getLineLength(char line[]);

int getLineLength(char line[]) {
  int c, i = 0;
  while((c = getchar()) != EOF && c != '\n') {
    line[i++] = c;
  }
  if(c == '\n') {
    line[i++] = c;
  }
  if(i > LIMIT - 1) {
    i = LIMIT - 1;
  }
  line[i] = '\0';
  return i;
}

int main() {
  char line[LIMIT];
  int len = 0;
  while((len = getLineLength(line)) > 0) {
    int contentLength = (len > 0 && line[len-1] == '\n') ? len - 1 : len;
    int start = 0;
    int end = N <= contentLength ? N : contentLength;

    while(start < contentLength) {
      int j = end - 1;
      while(j >= start && (line[j] == ' ' || line[j] == '\t')) {
        j--;
      }
      int breakAt = (j >= start) ? (j + 1) : end;
      int pringFrom = start;
      while(pringFrom < breakAt && (line[pringFrom] == ' ' || line[pringFrom] == '\t')) {
        pringFrom++;
      }
      if(pringFrom < breakAt) {
        for(int i = pringFrom; i < breakAt; i++) {
          putchar(line[i]);
        }
        putchar('\n');
      }
      start = breakAt;
      while(start < contentLength && (line[start] == ' ' || line[start] == '\t')) {
        start++;
      }

      end = start + N;
      if(end > contentLength) {
        end = contentLength;
      }
    }
    if(len > 0 && line[len-1] == '\n') {
      putchar('\n');  
    }
  }
  return 0;
}
