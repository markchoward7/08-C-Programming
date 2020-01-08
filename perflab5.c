/*
    Author: Mark Howard
    2020-Jan-08
    Performance Lab 5
*/

#include <stdio.h>

void main()
{
    int userInput = 0;                // Will store user input
    printf("Enter a character: ");    // Prompts user
    userInput = getchar();            // Stores user input
    printf("Your modified character is: ");   // Prefaces output
    putchar(userInput+1);               // Prints output
}