// Write a program to count blanks, tabs, and newlines. 


#include <stdio.h>

int main(){
    
    int c, nl, nb, nt;

    nb = 0;  /* number of blank*/
    nt = 0; /* number of tab */
    nl = 0; /* number of newline */
    while((c = getchar()) != EOF){
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }

    printf("%d %d %d\n",nb, nt,  nl);

}

/* The integer variables ab, nt, nl are used to count the number of blanks, tabs and newlines. initailly this variables are set equal to 0.*/
 


