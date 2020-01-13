/*
    Author: Mark Howard
    2020-Jan-13
    Performance Lab 14
*/

#include <stdio.h>

int main(void)
{
    // Declare variables
    int num1, num2;
    double result;
    char operator;
    // Get input from user
    scanf("%d %c %d", &num1, &operator, &num2);
    // Check which operator was given and perform the correct math
    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
        // Don't divide by zero
            if (num2 == 0)
            {
                printf("Error");
                return 0;
            }
            else
            {
                result = (double)num1 / num2;
                // Division will print here to allow 2 digit precision
                printf("%.2lf", result);
            }
            // Return instead of printing again below
            return 0;
        default:
        // If they put something that wasn't an operator
            printf("Error");
            return 0;
    }
    // Print the results
    printf("%.0lf", result);
    return 0;
}