// Write a program to print a histogram of the lenghts of words in its input. It is easy to draw the histograam with the bars horizontal; a vertical orienteation is more challenging.

#include <stdio.h>

#define MAXHIST 15    /* max length of histogram                   */
#define MAXWORD 11    /* max length of a word                      */
#define IN 1         /* inside a word                             */
#define OUT 0         /* outside a word                            */

/* print horizontal histogram                                      */

int main(){
        int c, i, nc, state;
        int len;                 /* lenght of each bar             */        
        int maxvalue;            /* maximum vlaue for wl[]         */
        int ovflow;              /* number of overflow words       */
        int wl[MAXWORD];         /* word length counters           */

        state = OUT; 
        nc = 0;                  /* number of chars in a word      */
        ovflow = 0;              /* number of words >= MAXWORD     */
        for (i = 0; i < MAXWORD; ++i)
            wl[i] = 0;
        while ((c = getchar()) != EOF ){
            if ( c == ' ' || c == '\n' || c == '\t'){
        state = OUT;
       if (nc > 0)
          if (nc < MAXWORD)
             ++ wl[nc];
          else
             ++ovflow;
           nc = 0; 
        } else if (state == OUT) {
             state = IN;
             nc = 1;          /* beginning of a new word   */
        } else
            ++nc;        /*inside a word              */
        }
        maxvalue = 0;
        for (i = 1; i < MAXWORD; ++i)
             if (wl[i] > maxvalue)
                 maxvalue = wl[i];
                     for (i = 1; i < MAXWORD; ++i){
                     printf("%5d %5d : ", i, wl[i]);
                    if (wl[i] > 0) {
                        len = (wl[i] *  MAXHIST ) / maxvalue ;
                            len = 1;
                    } else
                        len = 0;
                    while (len > 0) {
                    putchar ('x');
                    --len;
                    }
                    putchar('\n');
                     }
        if (ovflow > 0)
            printf("There are %d words >= %d\n", ovflow, MAXWORD);

}
 
/* A blank, newline or tab marls the end of a word. If there is a word (nc > 0) and ita length is less than the maximum word  length (nc < MAXWORD), then the program increments the appropriate word lenght counter (++wl[nc]). If teh kength if the word is out of range (nc >= MAXWORD). Then the program increment the variable ovflow that keeps track of the number of words grater than or equal to MAZWORD.
 * When all words have been read in the program determines the maximum vlaue(maxvalue) from teh array wl
 * The variable len scales the value in wl[i] according to MAXHIST and maxvalue . when wl[i] is greater than 0. at least one asterisk is printed*/

