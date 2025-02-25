/* Write a function rightrol(x,n) that returns the value of the integer x rotated to
the right n bit position */
/* rightrot: rotate x to the right by n position */

unsigned rightrot(unsigned x, int n)
{
  int wordlength(void);
  int rabit;   /* rightmost bit */


  while (n-- > 0){
    rbit = (x & 1) << (wordlength() - 1);
    x = x  >> 1; /* shift x 1 position right */
    x = x | rbit;  /* complete one rotation  */
    
  }
  return x;
  
  
}
