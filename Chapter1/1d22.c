#include <stdio.h>
#include <stdbool.h>

#define MAXLINE  1000
#define MAXLINES 10
#define FOLD_THRESHOLD 30
#define FOLD_ONLY_AFTER 30
#define IS_BLANK(c) ((c) == ' ' || (c) == '\t')

int my_getline(char *line, int maxLength);
void copy(char *from, char *to);
void fold(char *str, char *folded);

int main() {
      char text[MAXLINES][MAXLINE];
      char line[MAXLINE];
      char folded[MAXLINE];

      int cur_line = 0;
      int length;
      
      while ((length = my_getline(line, MAXLINE)) > 0) {
            fold(line, folded);
            copy(folded, text[cur_line]);
            cur_line++;
      }

      for (int i=0; i<=cur_line; ++i){
            printf("%s\n", text[i]);
      }

      return 0;
}


/*
* Keep in "mind" the last blank character (space or tab)
* upon reaching the threshold, either break the line at
* last non-blank character or break at stopped if there
* was not any blanks in the current line.
*/
void fold(char *str, char *folded) {
        char c;
        int lines = 1;
        int last_blank = -1;
        int i = 0;
        int j = 0;
        int k = 0;

        while (str[i] != '\0') {
                k = 0;
                while (k++ < FOLD_THRESHOLD) {
                        if (IS_BLANK(str[i+k])) {
                                last_blank = i+k;
                        }
                }
                k += j;
                if (last_blank == -1 /*|| last_blank < lines * FOLD_ONLY_AFTER*/) {
                        // Fold exactly at column number FOLD_THRESHOLD
                        for (; i <= k; i++) {
                                folded[j++] = str[i];
                        }
                        folded[j++] = '\n';
                } else {
                        // Fold at last_blank
                        for (; i < last_blank; i++) {
                                folded[j++] = str[i];
                        }
                        folded[j++] = '\n';
                }
                i++; // skipping the blank character (not needed to be printed on the folded line)
                lines++; // increasing the number of total lines
                last_blank = -1;
        }

        folded[j] = '\0';
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