// Modify the temperature conversion program to print the table in reverse order, tht is, from 300 degrees to 0.
//

#include <stdio.h>

/* print fahrenheit-celsius table in reverse order*/
int main(){
    int fahr;
    for(fahr = 300; fahr >=0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    return 0;
}

// the only modification in this 
// for(fahr = 3==; fahr >=0; fahr = fahr - 20)

