#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 3000
#define ERR_BYTES 300

bool code_check(char *str, char *checked);

int main() {
      char c_code[MAXLINE];
      char checked[MAXLINE];
      int i = 0;
      char c;

      while ((c = getchar()) != EOF) {
        c_code[i++] = c;
      }
      c_code[i] = '\0';

      code_check(c_code, checked);

      return 0;
}

bool code_check(char *str, char *checked) {
        int i = 0;
        char c;
        bool inside_block_comment = false,
             inside_line_comment = false,
             inside_string = false,
             inside_char = false;
        int braces_cnt = 0,
            brackets_cnt = 0,
            parentheses_cnt = 0;

        while ((c = str[i++]) != '\0') {
                if (inside_block_comment) {
                        if (c == '*' && str[i] == '/') {
                                inside_block_comment = false;
                                i++;
                        }
                        continue;
                } else if (inside_line_comment) {
                        if (c == '\n') {
                                inside_line_comment = false;
                                i++; // this is better, because not all line comments take the whole line. Like this one :)
                        }
                        continue;
                } else if (!inside_char &&
                           !inside_string &&
                           c == '/' && str[i] == '/') {
                        inside_line_comment = true;
                        i++;
                        continue;
                } else if (!inside_char && 
                           !inside_string && 
                           c == '/' && str[i] == '*') {
                        inside_block_comment = true;
                        i++;
                        continue;
                } else if (c == '\'') {
                        inside_char = !inside_char;
                } else if (c == '\"') {
                        inside_string = !inside_string;
                }

                if (!inside_string && !inside_char) {
                        switch (c) {
                                case '{':
                                        braces_cnt--;
                                        break;
                                case '}':
                                        braces_cnt++;
                                        break;
                                case '(':
                                        parentheses_cnt--;
                                        break;
                                case ')':
                                        parentheses_cnt++;
                                        break;
                                case '[':
                                        brackets_cnt--;
                                        break;
                                case ']':
                                        brackets_cnt++;
                                        break;                                
                        }
                }
        }

        if (braces_cnt != 0) {
                printf("Braces mismatch found\n");
        }
        if (brackets_cnt != 0) {
                printf("Brackets mismatch found\n");
        }
        if (parentheses_cnt != 0) {
                printf("Parentheses mismatch found\n");
        }
        if (!braces_cnt && !brackets_cnt && !parentheses_cnt) {
                printf("No mismatch found\n");
                return true;
        } 
        return false;
}