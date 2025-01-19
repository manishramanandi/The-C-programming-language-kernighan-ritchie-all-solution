// Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

#include <stdio.h>

// symbolic name
#define NONBLANK 'a' 

/* replace strinf of balnks with a single blank */

int main(){
    int c, lastc;
    lastc = NONBLANK;
    while((c = getchar()) != EOF){
        if (c != ' ')  
            putchar(c);
        if (c == ' ')
            if (lastc != ' ')
                putchar(c);
        lastc = c;
    } 
}

/* The integer variable c records the ASCII value of the present character received from the input and lastc records the ASCII value of the previous character. The symbolic constant NONBLANK initailizes lastc to an arbitary nonblank character.
 * The first if statement in the body of the while loop handles the occurence of nonblank it prints them. The second if statement handles blanks, and the third if statement tests for a single blank or the first blank of a string of blanks. Finally, lastc is updated. and the process repeats*/

