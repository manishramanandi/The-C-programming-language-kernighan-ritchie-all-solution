//Experiment to find out what happens when printf's argument string contain \c,
//where c is some character not listed above(excape sequence) 

#include <stdio.h>

int main(){
    printf("Hello, world\c");
    printf("Hello, world\y");
    printf("Hello world\j");
    return 0;

}

// I wrote \c,\y\j instead of the reserved escape sequence in C langauge, try it by yourself
