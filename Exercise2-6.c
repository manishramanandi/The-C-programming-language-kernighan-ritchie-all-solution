/* write a function setbits(x, p, n, y) that retunrs x with the n bits that begin all position p set to the rightmost n bits of y, leaving the other bits unchanged. */

#include <stdio.h>
/* setbits: set n bits of x at position p with bits of y */

unsigned setbits(unsigned x, int p, int n, unsigned y) {

  return x & ~(~(~0 << n) << (p+1-n)) |
        (y &  ~(~0 << n)) << (p+1-n);

}

int main(){
  printf("%u\n", setbits(170, 5, 3, 204)); //Example usage you can also change the value
  return 0;
}

// it will return 162
