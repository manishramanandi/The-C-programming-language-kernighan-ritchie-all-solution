// Write a function reverse() that reverse the character string s. Use it to write a program that reverses the input at a time.

#include  <stdio.h>
#define     MAXLINE 1000        /* Maximum input line size */

int my_getline(char line[], int maxline);
void reverse(char s[]);

/* reverse input lines, a line at a time        */

int main() {
            char line[MAXLINE];            /* current input line  */

                while( my_getline( line,MAXLINE ) > 0){
               reverse(line);
               printf("%s", line);

                }
                return 0;

}

int my_getline(char s[], int maxline) {
            int c, i;

            for(i=0;i < maxline -1 && (c = getchar()) != EOF && c != '\n'; ++i){
           s[i] = c;
}

if (c == '\n'){
    s[i] = c;
    ++i;
}

s[i] = '\0'; /* NuLL-terminate the string  */
return i;
}

/* reverse: reverse string s            */

void reverse(char s[]){
        int i, j;
        char temp;

        i = 0;
        while (s[i] != '\0')       /* find the end of string s */
            ++i;
        --i;  /* back off from '\0'    */
        if (s[i] == '\n')  
            --i;
        j = 0;
        while(j < i) {
        temp = s[j];
        s[j] = s[i];   /* swap the characters   */
        s[i] = temp;
        --i;
        ++j;
        }
}
  
/* The reverse function first finds the end of string s. It then backs off one position from '\0', so that the first character will not become an end of string marker. If a '\n' exist, it backs off one more position, since like the '\0', it must at the end of teh line.
 * j is the index of the first character of the string and i is the index of the last character of teh string. while swapping characters, j is incremented(moves toward the end of teh string), and i is decrement (moves toward the beggining od the string), The process continues while j is less than i.
 * The main process rads a line of input at a time, reverse it , and prints the reverse line.           */

       



