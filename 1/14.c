/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input. */

#include <stdio.h>

int main() {
  int c;
  int freq[26] = {0};

  while((c = getchar()) != EOF) {
    freq[c - 'a']++;
  }

  for(int i = 0; i < 26; i++) {
    printf("%c: %d\n", (97 + i), freq[i]);
  }
  return 0;
}

