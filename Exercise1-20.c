#include <stdio.h>

#define TABINC 8  /* tab increment size  */

/* replace tabs with the proper number of blanks */
int main() {
    int c, nb, pos;

    nb = 0;             /* number of blanks necessary */
    pos = 1;            /* position of character in line */

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            nb = TABINC - (pos - 1) % TABINC;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n') { /* newline character */
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
    return 0;
}

/* The tab stops are at TABINC position. In this program TABINC is defined to be 8. The variable pos is teh position within in a line of text where the program curarently is.
 * IF the charactaer is a tab, the program calculates the number of blanks nb necessary to reach the next tab stop. The statement
 *
 * nb = TABINC - (pos - 1) % TABINC
 *
 * determines this value. IF the character is a newline tehn it is printed out and pos is reintialized to the begining of the line (pos = 1). Any other character is printed and pos is incremented(++pos)
 *
 * TABINC is a symbolic constant */
