// Write a program to print all input lines that are longer than 80 characters.

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size  */
#define LONGLINE 80

/* function to get line of input */
int my_getline(char line[], int maxline){
        int c, i;
        for (i = 0; i < maxline -1 && (c = getchar()) != EOF && c != '\n'; ++i)
            line[i] = c;
        if(c == '\n'){
          line[i] = c;
         ++i;

        }
        line[i] = '\0'; /* Null terminate the tring */
        return i;

}

/* print line longer than LONGLINE      */
int main(){
        int len;           /* current line length*/
        char line[MAXLINE];     /* current input line */
        while ((len  =my_getline(line, MAXLINE)) > 0)
            if (len > LONGLINE)
                    printf("%s", line);
        return 0;

}

/* The program invokes getline to read an input line getline eturn the length of the line and as much text as possible. If the length is greater than 80 cahracters(LONGLINE). then the program prints the input line. Other wise, no action is taken. The loop repeats until getline returns length zero.  */
