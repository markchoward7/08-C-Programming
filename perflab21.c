/*
    Author: Mark Howard
    2020-Jan-15
    Performance Lab 21
*/

#include <stdio.h>

// Recursive function to get the "Shadow Sequence number"
// 1 = 9, 2 = 0, S(n) = S(n-1) + (n * n)
unsigned long shadow(unsigned long num)
{
    if (num == 1)
    {
        return 9;
    }
    if (num == 2)
    {
        return 0;
    }
    return shadow(num - 1) + (num * num);
}

int main(void)
{
    // Get user input
    printf("Enter a number:\n");
    unsigned long num = 0;
    scanf("%lu", &num);
    // Start the recursion function and print the result
    printf("%lu", shadow(num));
    return 0;
}