// Write a program that prints its input one word per line.

#include <stdio.h>

#define IN 1    /*inside a word */
#define OUT 0   /*outside a word */

/* print input one word per line */
int main(){
   int c, state;

   state = OUT;
   while((c = getchar()) != EOF){
   if (c == ' ' || c == '\n' || c == '\t' ) {
               if(state == IN) {
               putchar('\n');  /* finish the word */
               state = OUT;
               }
   } else if (state == OUT) {
        state = IN; /* beginning of word */
       putchar(c); 
   
   } else          /* inside a word */
       putchar(c);

}
}

/* State is an integer bollean that records whether the program is currently inside a word or not. At the beginning of the program, state is isitialized to OUT. since no date has been processed.
 * the first if statement
 *  
 *  if(c == ' ' c == '\t' c == '\n')
 *  determines whether c is a word separator. If it is, then the secod if statement,
 *  if (state == IN)
 *
 *  determines whether this wor separator signifies the end of a word. If so, a newline is printed and state is updated; otherwise no action is taken.
 *  if c is not a word separator, then it is eitehr the first character od a word or another cahracter withing the word. If it is the beginning of a new word, then the program updates state. In either case, the character is printed. */
