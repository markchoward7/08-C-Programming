/*
    Author: Mark Howard
    2020-Jan-14
    Performance Lab 18
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // Declare variables
    uint32_t num;
    scanf("%d", &num);
    // While True
    while (1)
    {
        // Demonstrate break on input of over 999
        if (num > 999)
        {
            break;
        }
        // Take the first 10 numbers and otherwise increment until half the user input
        for (int counter = 0, num2 = 0; counter < 10 && num2 <= num/2; num2++)
        {
            // Demonstrate continue on an easily avoidable divide by zero
            if (num2 == 0)
            {
                continue;
            }
            // Print any numbers that evenly divide into the input
            if (num % num2 == 0)
            {
                printf("%d\n", num2);
                counter++;
            }
        }
        // Print the initial number and then get new input
        printf("%d\n", num);
        scanf("%d", &num);
    }
    return 0;
}