/*
    Author: Mark Howard
    2020-Jan-13
    Performance Lab 16
*/

#include <stdio.h>

int main(void)
{
    // Initialize the char array
    char phrases[256] = {"A man chooses, a slave obeys\nDude, where's my car?\nWhere's the money, Lebowski?"};
    // Puts it to the terminal
    puts(phrases);
    // Initialize a counter variable
    int counter = 0;
    // Loop through the char array and putchar each character
    while (phrases[counter] != 0)
    {
        putchar(phrases[counter]);
        counter++;
    }
    return 0;
}