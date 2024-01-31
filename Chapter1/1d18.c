#include <stdio.h>
#include <string.h> // sorry for this ;(

#define MAXLINE 1000

int my_getline(char *s, int lim);
int remove_tail(char *s);

int main () {
      int len;
      int remaining_str;
      char line[MAXLINE];

      while ((len = my_getline(line, MAXLINE)) > 0) {
            remaining_str = remove_tail(line);

            if (remaining_str != 0) {
                  puts(line);
            }

            memset(line, 0, MAXLINE);
      }
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
      s[++i] = '\0';
      return i;
}

int remove_tail(char *s) {
      int i = 0;

      while (s[i] != '\0') {
            i++;
      }
      i--;
      while (s[i] == ' ' || s[i] == '\t') {
            s[i] = '\0';
            i--;
      }

      /* Test to see if cut worked because I could not check in my terminal
      * if (i != 0) {
      *       s[++i] = '$';
      * }
      */
      return i;
}