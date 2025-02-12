#include <stdio.h>

void remove_comment(int c);
void in_comment(void);
void echo_quote(int c);

/* remove all comments from a valid C program */
int main() {
    int c;

    while ((c = getchar()) != EOF) 
        remove_comment(c);
    
    return 0;
}

/* remove_comment: read each character and remove comments */
void remove_comment(int c) {
    int d;
    
    if (c == '/') {
        if ((d = getchar()) == '*') {
            in_comment();   /* beginning comment */
        } else if (d == '/') {
            putchar(c);     /* another slash (probably a C++ style comment, which we ignore) */
            remove_comment(d);
        } else {
            putchar(c);     /* not a comment */
            putchar(d);
        }
    } else if (c == '\'' || c == '"') {
        echo_quote(c);   /* quote begins */
    } else {
        putchar(c);   /* not a comment */
    }
}

/* in_comment: skip characters inside a comment */
void in_comment(void) {
    int c, d;

    c = getchar();  /* previous character */
    d = getchar();  /* current character */
    
    while (c != '*' || d != '/') {  /* search for end of comment */
        c = d;
        d = getchar();
    }
}

/* echo_quote: echo characters inside quotes while handling escape sequences */
void echo_quote(int c) {
    int d;

    putchar(c);
    while ((d = getchar()) != c) {  /* search for end */
        putchar(d);
        if (d == '\\')  /* handle escape sequences inside quotes */
            putchar(getchar());
    }
    putchar(d);
}

/* The program assumes that the input is a valid C program. ecomment searches for the beginning of a comment (/*) and when it finds it calls in_comment. This functions searches for the end of the comment. The procedure tehrefore ensures that a comment will be ignored. */
