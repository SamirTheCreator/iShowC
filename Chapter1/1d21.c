#include <stdio.h>

#define MAXLINE  1000
#define MAXLINES 10
#define TAB_STOP 8

void entab(char *str, char *entabbed);
int my_getline(char *line, int maxLength);
void copy(char *from, char *to);

int main() {
      char text[MAXLINES][MAXLINE];
      char line[MAXLINE];
      char entabbed[MAXLINE];

      int cur_line = 0;
      int length;
      
      while ((length = my_getline(line, MAXLINE)) > 0) {
            entab(line, entabbed);
            copy(entabbed, text[cur_line]);
            cur_line++;

            for (int j=0; j < length; j++) {
                if (entabbed[j] == '\t') {
                        printf("tab found\n");
                }
            }
      }

      for (int i=0; i<=cur_line; ++i){
            printf("%s\n", text[i]);
      }

      return 0;
}

void entab(char *str, char *entabbed) {
        int i = 0;
        int j = 0;
        char c;
        int space_cnt = 0;
        while ((c = str[i++]) > 0) {
                if (c == ' ') {
                        space_cnt++;
                        if (((i + 1) % TAB_STOP) == 0) {
                                entabbed[j++] = '\t';
                                space_cnt = 0;
                        }
                } else {
                        for (int k = 0; k < space_cnt - 1; k++) {
                                entabbed[j++] = ' ';
                        }
                        space_cnt = 0;
                        entabbed[j++] = c;
                }
        }
        entabbed[j] = '\0';
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