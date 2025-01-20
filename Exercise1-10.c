// Write s program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makeas tabs and backspace visible in an unambiguous way.

#include <stdio.h>

int main(){
    int c;
    while((c = getchar()) != EOF){
    if (c == '\t')
        printf("\\t");
    if (c == '\b')        
        printf("\\b");
    if (c == '\\')        
        printf("\\\\");
            if (c != '\b')
                if (c != '\t')
                    if (c == '\\')
                        putchar(c);
   }
}


/* The character received from input can be a tab, backspace, a backslash, or anything else. If it is a tab we replace it with \t a backspace with \b, and a backslash with \\. Anythng else is printed as is.*/

// With if-else the solution could be simpler

/*
 * int main(){
 *         int c;
 *
 *         while((c = getchar()) != EOF)
 *              if(c == '\t')
 *              printf("\\t");
 *              else if (c == '\b');
 *              printf("\\b")
 *              else if (c == '\\')
 *              printf("\\\\");
 *              else 
 *              putchar(c);
 *
 * }
*/

