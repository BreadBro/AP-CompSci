//Safin Stefanos
//Converting Celsius to Fahrenheit
//09/14/2021
#include <stdio.h>
#include <cs50.h>
#include <string.h>

float c2f(float temp) {
    //math
    float fahrenheit = ((temp*9)/5) + 32;
    return fahrenheit;
}

float f2c(float temp) {
    //math
    float celsius = (temp - 32) * 5/9;
    return celsius;
}

int main(void) {
    //celsius variable
    float cels = 0;
    //celsius variable
    float fahr = 0;
    char choice = get_char("Would you like to convert from Fahrenheit or Celsius? (f or c): ");
    //checks if the choice is c, if choice is c, it returns 0
    int result  = strcmp(&choice, "c");
    if (result == 0) {
        cels = get_int("C: ");
        fahr = c2f(cels);
        printf("F: %1.f\n", fahr);
    }
    else {
        fahr = get_int("F: ");
        cels = f2c(fahr);
        printf("C: %1.f\n", cels);
    }
}

