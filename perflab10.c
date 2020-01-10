/*
    Author: Mark Howard
    2020-Jan-10
    Performance Lab 10
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // Initialize and retrieve userInput
    uint32_t userInput;
    fscanf(stdin, "%d", &userInput);
    // Initialize bitChecker and set the leftmost bit to on and all others to off
    uint32_t bitChecker = 0x01;
    bitChecker = bitChecker << 31;
    // While loop to check each individual bit on userInput against bitChecker using bitwise and
    // Print the results
    while (bitChecker > 0)
    {
        fprintf(stdout, "%d", (userInput & bitChecker) > 0);
        bitChecker = bitChecker >> 1;
    }
    
}