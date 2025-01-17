// Write a program to print the value of EOF.

#include <stdio.h>

int main(){
    printf("EOF is %d\n",EOF);

}

/* The symbolic constant EOF is defined in <stdio.h>. The EOF outside the double quotes in printf() is replaced by whatever text follows
 *
 * #define EOF
 *
 * in the include file. In our system EOF is -1, but it may be vary from system to system. That's why standard symbolic constant like EOF help make your program portable
