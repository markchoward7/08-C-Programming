/*
    Author: Mark Howard
    2020-Jan-08
    Performance Lab 6
*/

#include <stdio.h>

void main()
{
    int userInput = 0;                // Will store user input
    printf("Enter a character: ");    // Prompts user
    userInput = getc(stdin);            // Stores user input
    printf("Your modified character is: ");   // Prefaces output
    putc(userInput-1, stdout);               // Prints output
}