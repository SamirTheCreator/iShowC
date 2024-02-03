#include <stdio.h>
#include <string.h> // sorry to let you down again

#define MAXLINE 1000

int my_getline(char *s, int lim);
void my_reverse(char *s, int len);

int main () {
      char line[MAXLINE];
      int len;

      while ((len = my_getline(line, MAXLINE)) > 0) {
            my_reverse(line, len);
            puts(line);
            memset(line, 0, MAXLINE);            
      }

      return 0;
}

int my_getline(char *s, int lim) {      
      int c, i;

      for (i=0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
            s[i] = c;
      }

      /* Is this really necessary?
      * if (c == '\n') {
      *       s[i] = c;
      *       ++i;
      * }
      */
     if (c != EOF) 
            s[++i] = '\0';
      return i;
}

void my_reverse(char *s, int len) {
      char tmp;

      for (int i=0; i < len / 2; ++i) {
            tmp = s[i];
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = tmp;
      }
}