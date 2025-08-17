/* Exercise 1-23. Write a program to remove all comments from a C program.
Don't forget to handle quoted strings and character constants properly. C comments do not nest. */
#include <stdio.h>

typedef enum {
  NORMAL,
  SLASH_SEEN,
  IN_BLOCK_COMMENT,
  IN_LINE_COMMENT,
  IN_STRING,
  IN_CHAR
} State;

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  char *filename = argv[1];

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }
  int c;
  State state = NORMAL;

  while((c = fgetc(fp)) != EOF) {
    switch(state) {
      case NORMAL: {
        if(c == '"') {
          putchar('"');
          state = IN_STRING;
        }
        else if(c == '\'') {
          putchar('\'');
          state = IN_CHAR;
        }
        else if(c == '/') {
          state = SLASH_SEEN;
        }
        else {
          putchar(c);
        }
        break;
      }
      case SLASH_SEEN: {
        if(c == '*') {
          state = IN_BLOCK_COMMENT;
        }
        else if(c == '/') {
          state = IN_LINE_COMMENT;
        }
        else {
          putchar(c);
          state = NORMAL;
        }
        break;
      }
      case IN_LINE_COMMENT: {
        if(c == '\n') {
          putchar(c);
          state = NORMAL;
        }
        else {
          state = IN_LINE_COMMENT; 
        }
        break;
      }
      case IN_BLOCK_COMMENT: {
        if(c == '*') {
          int d = fgetc(fp);
          if(d == '/') {
            state = NORMAL;
          }
          else {
            if(d != EOF) {
              ungetc(d, fp);
            }
          }
        }
        break;
      }
      case IN_STRING: {
        putchar(c);
        if(c == '\\') {
          int d = fgetc(fp);
          putchar(d);
        }
        else if(c == '"') {
          state = NORMAL;
        }
        break;
      }
      case IN_CHAR: {
        putchar(c);
        if(c == '\\') {
          int d = fgetc(fp);
          putchar(d);
        }
        else if(c == '\'') {
          state = NORMAL;
        }
        break;
      }
      default: {
        putchar(c);
        break;
      }
    } 
  }

  fclose(fp);
  return 0;
}

