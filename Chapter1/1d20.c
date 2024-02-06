#include <stdio.h>
#include <string.h>

#define MAXLINE  1000
#define MAXLINES 10
#define TAB_STOP 8

int detab(char *str, char *detabbed);
int my_getline(char *line, int maxLength);
void copy(char from[], char to[]);

int main() {
      char text[MAXLINES][MAXLINE];
      char line[MAXLINE];
      char detabbed[MAXLINE];

      int cur_line = 0;
      int length;
      
      while ((length = my_getline(line, MAXLINE)) > 0) {
            detab(line, detabbed);
            copy(detabbed, text[cur_line]);
            cur_line++;
            memset(line, 0, length);
            memset(detabbed, 0, length);
      }

      for (int i=0; i<=cur_line; ++i){
            printf("%s\n", text[i]);
      }

      return 0;
}


int detab(char *str, char *detabbed) {
      char c;
      int i = 0, j = 0;
      int tab_cnt = 0;
      int spaces;
      while ((c = str[i++]) != '\0') {
            if (c == '\t') {
                  tab_cnt++;
                  spaces = TAB_STOP - (j % TAB_STOP);
                  for (int k=0; k < spaces; k++) {
                        detabbed[j++] = ' ';
                  }
            } else {
                  detabbed[j++] = c;
            }
      }
      detabbed[j] = '\0';
      return tab_cnt;
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