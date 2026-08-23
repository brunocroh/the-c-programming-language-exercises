/*
“Exercise 1-23. Write a program to remove all comments from a C program.
Don’t forget to handle quoted strings and character constants properly.
C comments do not nest.”

Excerpt From
The C Programming Language, Second Edition (for    )
Brian W. Kernighan
This material may be protected by copyright.
*/
#include <stdio.h>

#define MAX 1000
#define IN  1
#define OUT 1

// This is a test comment.

int get_str(char str[], int max);
void remove_comments(char str[], char str_output[]);

int main() {
  char str[MAX];
  char str_output[MAX];

  get_str(str, MAX);

  remove_comments(str, str_output);

  printf("====== OUTPUT =======");
  printf("%s", str_output);

  return 0;
}

int get_str(char str[], int max) {
  int i, c;

  for(i = 0; i < max-1 && (c = getchar()) != EOF; i++) {
    str[i] = c;
  }

  str[i] = '\0';

  return i;
}

void remove_comments(char str[], char str_output[]) {
  char c;
  int i, j;
  int is_quote = 0;
  int is_block_comment = 0;
  int is_line_comment = 0;

  i = j = 0;

  while(str[i] != '\0') {
    c = str[i];
    if(!is_block_comment && !is_line_comment) {
      if(str[i] == '"') {
        is_quote = is_quote == 0 ? 1 : 0;
      }
    }

    if(!is_quote) {
      if(!is_block_comment && !is_line_comment) {
        if(str[i] == '/') {
          if(str[i+1] == '*') {
            is_block_comment = 1;
          }

          if(str[i+1] == '/') {
            is_line_comment = 1;
          }
        }
      } 

      if(is_block_comment) {
        if(str[i] == '*' && str[i+1] == '/') {
          is_block_comment = 0;
        }
      }

      if(is_line_comment) {
        if(str[i] == '\n') {
          is_line_comment = 0;
        }
      }
    }

    if(!is_block_comment && !is_line_comment) {
      str_output[j++] = str[i++];
    } else {
      i++;
    }
  }
}
