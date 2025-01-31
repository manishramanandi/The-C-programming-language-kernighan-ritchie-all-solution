// Rewrite the temperature conversion program of section 1.2 to use a function for conversion


#include <stdio.h>

 float celsius(float fahr);


int main() {

    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper){
        printf("%3.0f %6.1f\n", fahr, celsius(fahr));
        fahr = fahr + step;
    }
}

/* celsius: convert fahr into clesius */

float celsius(float fahr){
            return(5.0/9.0) * (fahr-32.0);
}

/* We use a function to convert Fahrenheit into celsius. The name of the function is clesiius, It receives a floating point value and return a floaating point value. The function return the value of the expression via the retunr statement.*/ 
