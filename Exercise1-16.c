// Revise the main routine of the longest-line program so it will correctly print the length of arbitarily long input lines, and as mush as possible of the text.


#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len;               /* Current line length */
    int max;               /* Maximum length seen so far */
    char line[MAXLINE];    /* Current input line */
    char longest[MAXLINE]; /* Longest line saved here */

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        printf("%d, %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) { /* There was a line */
        printf("Longest line: %s", longest);
    }

    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

