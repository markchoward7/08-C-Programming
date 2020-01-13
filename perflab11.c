/*
    Author: Mark Howard
    2020-Jan-13
    Performance Lab 11
*/

#include <stdio.h>

int main(void)
{
    // Declare a string and get the input from the user
    char myString[256] = {0};
    scanf("%255[^\n]s", &myString);
    // Print the string if it doesn't start or end with an abnormal character
    if (myString[0] >= 32 && myString[0] < 126)
    {
        printf("%s", myString);
    }

    return 0;
}