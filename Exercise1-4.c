// Write a program to print the corresponding clesius to fahrenheit table.

#include <stdio.h>

int main(){
    float fahr, celsius;
    int lower, step, upper;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius Fahr\n");
    celsius = lower;
    while(celsius <= upper){
    fahr = (9.0*celsius) / 5.0 + 32.0;
    printf("%3.0f  %6.1f\n", celsius, fahr);
    celsius = celsius + step;
} 
}
/* The program produces a table containing temperatures in degrees
celsius (0-300) and their equivalent fahrenheit values. Degrees fahrenheit are calculated using the statement:

fahr = (9.0*celsius) / 5.0 + 32.0

The solution follows the same logic as used in the program that prints the Fahrenheit-Celsius. The integer variable lower, upper, and step refer to the lower limit, upper limit, and step size of the variable celsius, respectively. The variable celsius initialized to the lower limit. and inside the while loop the equivalent fahrenheit temperature is calculated. The program prints celsius and fahrenheit and increments the variable celsius by the step size. The while loop repeats until the varaible celsius exceeds its upper limit.*/



