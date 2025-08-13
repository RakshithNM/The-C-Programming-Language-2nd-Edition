/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time. */
#include <stdio.h>
#define LIMIT 1000

void reverse(char s[], int length);
int getLineLength(char line[], int limit);

int main() {
  char line[LIMIT];
  int i = 0;
  int len = 0;
  while((len = getLineLength(line, LIMIT)) > 0) {
    reverse(line, len - 1);
	  printf("%s\n", line);
  }
	return 0;
}

void reverse(char s[], int length) {
  char temp[length + 1];
  for(int i = 0; i < length; ++i) {
    temp[i] = s[length - 1 - i];
  }

  temp[length] = '\0';

  for(int j = 0; j <= length; ++j) {
    s[j] = temp[j];
  }
}

int getLineLength(char line[], int limit) {
  int c, i = 0;
  while((c = getchar()) != EOF && c != '\n') {
    line[i++] = c;
  }
  if(c == '\n') {
    if(i > limit) {
      i = limit - 1;
    }
    line[i++] = c;
  }
  line[i] = '\0';
  return i;
}

