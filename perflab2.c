/*
    Author: Mark Howard
    2020-Jan-07
    Performance Lab 2

    Do some type conversions
*/

#include <stdio.h>

void main()
{
    // Declare and initalize some variables to convert
    int myInt = 100;
    float myFloat = 50.5;
    double myDouble = 75.5;
    char myChar = 'X';

    // Convert and print stuff
    printf("Int to float: %f\n", (float)myInt);
    printf("Int to char: %c\n", (char)myInt);
    printf("Float to double: %lf\n", (double)myFloat);
    printf("Double to float: %f\n", (float)myDouble);
    printf("Char to int: %d\n", (int)myChar);
    printf("33 to char: %c\n", (char)33);
}