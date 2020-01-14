/*
    Author: Mark Howard
    2020-Jan-14
    Performance Lab 19
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // Get input from user
    printf("Even or odd?\n");
    char response = tolower(getchar());
    // Set input pointer to end of stdin
    fseek(stdin, 0, SEEK_END);
    // For loop to go through 0-100
    for (int i = 0; i <= 100; i++)
    {
        // If checks for even or odd numbers to print
        if (response == 'e' && i % 2 == 0)
        {
            printf("%d\n", i);
        }
        else if (response == 'o' && i % 2 == 1)
        {
            printf("%d\n", i);
        }
        // If the number wasn't printed, continue
        else
        {
            continue;
        }
        // Otherwise, ask the user if they want to keep going or break
        printf("Continue?\n");
        if (tolower(getchar()) == 'n')
        {
            break;
        }
        // Set input pointer to end of stdin
        fseek(stdin, 0, SEEK_END);
    }
    return 0;
}