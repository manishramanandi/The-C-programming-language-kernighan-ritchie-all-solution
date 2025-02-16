/* Write a loop equivalent to the for loop above without using && or ||  */

/* original    */
/*   for(i=0; i<lim-1 && (c = getchar)) != '\n' && c != EOF; ++i)  */

enum loop { NO, YES };  // enumeration for continous number naemd loop wit 0 and 1
enum loop okloop = YES; // okloop initializes to 1(yes)

i = 0; // i initializes to 0 i is likely used as an index to store characters in an array (s[])
 
while (okloop == YES)  // this is an infinite loop that keeps running until okloop is set to No
    (i >= lim - 1) /* outside of valid range ? */
        okloop = NO;
else if ((c = getchar()) == '\n') okloop = NO; // the user press enter ('\n')
else if (c == EOF) /* end of file ?  */
    okloop = NO;
else {
    s[i] = c;
    ++i;
}

