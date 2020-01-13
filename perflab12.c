/*
    Author: Mark Howard
    2020-Jan-13
    Performance Lab 12
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // Initialize and retrieve userInput
    int userInput;
    fscanf(stdin, "%d", &userInput);
    // Initialize bitChecker and set the leftmost bit to on and all others to off
    uint32_t bitChecker = 0x01;
    bitChecker <<= 31;
    // Check if number is positive or negative
    // If it is positive, make it negative
    if (userInput & bitChecker)
    {
        printf("The number is negative.\n");
    }
    else
    {
        printf("The number is positive, making it negative...\n");
        userInput = userInput | bitChecker;
    }
    
    // While loop to check each individual bit on userInput against bitChecker using bitwise and
    // Print the results
    while (bitChecker > 0)
    {
        fprintf(stdout, "%d", (userInput & bitChecker) > 0);
        bitChecker >>= 1;
    }
    
}