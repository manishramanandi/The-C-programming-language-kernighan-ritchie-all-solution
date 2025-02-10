/* Write a program entab that replaces string pf blanks by the minimum number of tabs and blanks to achieve
the same spacing. Use the same tab stops as for detab.
when either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>

#define TABINC 8 /* Tab increment size */

/* Replace strings of blanks with tabs and blanks */
int main() {
    int c, nb, nt, pos;

    nb = 0;  /* Number of spaces needed */
    nt = 0;  /* Number of tabs needed */
    pos = 1; /* Current position */

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            /* If space is encountered, determine whether to count as a blank or a tab */
            if (pos % TABINC == 0) {
                /* We have reached a tab stop, so convert to a tab */
                ++nt;
                nb = 0; /* Reset the number of blanks */
            } else {
                ++nb; /* Increment the blank counter */
            }
        } else {
            /* Output the stored tabs and spaces before printing the non-space character */
            for (; nt > 0; --nt)
                putchar('\t'); /* Print tab(s) */

            for (; nb > 0; --nb)
                putchar(' '); /* Print space(s) */

            putchar(c); /* Print the actual character */

            /* Reset position tracking */
            if (c == '\n') {
                pos = 0; /* Reset to start of new line */
            } else if (c == '\t') {
                /* Adjust position for tab */
                pos += (TABINC - (pos - 1) % TABINC) - 1;
            }
        }
        ++pos; /* Move to next position */
    }
    return 0;
}

/* The integer variables nb and nt are the minimum number of blanks and tabs necessary
to replace a string of blanks. The variable pos is the position withing a line
of text where the program currently is.
The idea is to find all blanks. A string of blanks is replaced by a tab every
time pos reaches a multiple of TABINC.
When a program finds a nonblanks. then it prints the tabs and blanks accumulated
followed by the nonblank character. The program resets nb and nt to zero, and resets pos to teh
beginning of teh line if the current character is a newline.
If the nonblank character is a tab tehn the program prints only teh accumulated tabs followed by the current
tab character.
when a single b;anks suffices to reach a tab stop, it is easier to replace it
with a tab because we avoid special cases.*/
