#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int my_getline(char line[], int maxline);
int my_remove(char s[]);

/* Remove trailing blanks and tabs, and delete blank lines */
int main() {
    char line[MAXLINE]; /* current input line */

    while (my_getline(line, MAXLINE) > 0) {
        if (my_remove(line) > 0) {  // Only print non-empty lines
            printf("%s", line);
        }
    }
    return 0;
}

/* Read a line into s, return length */
int my_getline(char s[], int maxline) {
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';  // Null-terminate the string
    return i;
}

/* Remove trailing blanks and tabs from s */
int my_remove(char s[]) {
    int i = 0;

    while (s[i] != '\n' && s[i] != '\0') { // Find newline character
        ++i;
    }
    --i; // Move back before '\n'

    // Remove trailing spaces and tabs
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        --i;
    }

    if (i >= 0) {  // If the line is not completely empty
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }

    return i; // Return new length (0 means empty line)
}
