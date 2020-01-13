/*
    Author: Mark Howard
    2020-Jan-13
    Performance Lab 13
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // Declare variables and get user input in first two
    uint32_t num1, num2, num3;
    scanf("%d %d", &num1, &num2);
    // Print error and exit program if num1 and num2 are the same
    if (num1 == num2)
    {
        printf("ERROR");
        return 0;
    }
    // Otherwise copy the larger value to num3
    else if (num1 > num2)
    {
        num3 = num1;
    }
    else
    {
        num3 = num2;
    }
    // Print the sum if greater than 2
    if ((num1 + num2 + num3) > 2)
    {
        printf("%d", num1 + num2 + num3);
    }
    
    
    return 0;
}