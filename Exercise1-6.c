// Verify that the expression getchar() != EOF is 0 or 1.

#include <stdio.h>

int main(){
    int c;

    while(c = getchar() != EOF)
        printf("%d\n",c);

}

/* The expression
 * c = getchar() != EOF
 * is equivalent to 
 * c = (getchar() != EOF)
 *
 * The program reads characters from the standard input and uses the expression above. while getchar has a character to read it does not return the end of file and
 *
 * getchar() != EOF 
 *
 * is true. So 1 is assigned to c. When the program encounters the end of file. the program is flase . Then () is assigned to c and the loop terminates
