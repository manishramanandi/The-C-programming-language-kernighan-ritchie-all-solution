/* Write a program to "fold" long input lines into two or more shorter lines after the last non-blanks character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specifies column. */

#include <stdio.h>

#define  MAXCOL  10      /* maximum column of input */
#define  TABINC  8       /* tab increment size      */

char line[MAXCOL];        /* input line   */

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

/* fold long input lines into two or more shorter lines */

int main(){
             int c, pos;

            pos = 0;                /* postion in the line      */
            while ((c = getchar()) != EOF){
                line[pos] = c;    /* store current character  */
                if (c == '\t')    /* expand tab character     */
                    pos = exptab(pos);
                else if (c == '\n') {
                    printl(pos);   /* print current input line  */
                    pos = 0;
                } else if (++pos >= MAXCOL){
                pos = findblnk(pos);
                printl(pos);
                pos = newpos(pos);
                }
            }
}

/* printl: print line until pos column   */

void printl(int pos)
{
    int i;
    for(i = 0; i<pos; ++i)
        putchar(line[i]);
    if (pos > 0)    /* any char printed ?  */
        putchar('\n');
}

/* extab: expand tab into blanks   */
int exptab(int pos)
{
        line[pos] = ' ';   /* tab is at least one blank  */
        for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
            line[pos]  = ' ';
        if (pos < MAXCOL)   /* room left in current line  */
            return pos;
        else {
        printl(pos);
        return 0;       /* reset current position       */
        }
        }

/* findblnk: find blanks's position             */

int findblnk(int pos)
{

    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)           /* no blanks in the line ? */
       return MAXCOL-1;
    else                    /* at least one blank       */
       return pos+1;        /* postion after the blank  */
}

/* newpos ; rearrange line with new postion         */
int newpos(int pos)
{
    int i, j;

    if (pos <= 0 || pos >= MAXCOL)
        return 0;       /* nothing to rearrange */
    else {
            i = 0;
           for (j = pos; j < MAXCOL && line[j] != '\0'; ++j) {
           line[i] = line[j];
           ++i;
           }
           return i;  /* new position in line  */

    }
}

/* MAXCOL is a symbolic constant. It indicates the n-th column of input.
The integer variable pos points to the position within a line of taxt
where the program currently is. The program folds input lines before the n-th column of input.
    The program expand tab characters, prints teh current input when it finds
a newline, and folds the input line when pos reaches MAXCOL.
    The function findblnk searches for a blank starting at the index pos.
It returns the postion after a blank or MAXCOL if a blank does not exist.
    printl prints the character between position zero and pos-1.
    newpos rearrange a line, that is, it copies character, starting at pos,to
    // the beginning of the line, then returns teh new value of pos*/
