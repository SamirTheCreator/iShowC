#include <stdio.h>
#include <stdbool.h>

#define MAXLINE  1000
#define MAXLINES 50

int my_getline(char *line, int maxLength);
void copy(char *from, char *to);
void nocomment(char *str, char *nocommented);

int main() {
      char text[MAXLINES][MAXLINE];
      char line[MAXLINE];
      char nocommented[MAXLINE];

      int cur_line = 0;
      int length;
      

      while ((length = my_getline(line, MAXLINE)) > 0) {
            nocomment(line, nocommented);
            copy(nocommented, text[cur_line]);
            cur_line++;
      }

      for (int i=0; i<=cur_line; ++i){
            printf("%s\n", text[i]);
      }

      return 0;
}

void nocomment(char *str, char *nocommented) {
        int i = 0, j = 0;
        char c;
        bool inside_block_comment = false;
        bool inside_line_comment = false;
        bool inside_string = false;
        bool inside_char = false;

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

                nocommented[j++] = c;
        }
        nocommented[j] = '\0';
}

int my_getline(char *line, int maxLength) {      
      char ch;
      int length = 0;
      while ((ch = getchar()) != EOF && ch != '\n' && length < maxLength) {
          line[length] = ch;
          length++;
      }
      if (ch == '\n') {
          line[length] = '\0';
      }
      return length;
}

void copy(char *from, char *to) {
    int i = 0;
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}