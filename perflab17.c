/*
    Author: Mark Howard
    2020-Jan-13
    Performance Lab 17
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // Initialize variables
    int nums[26] = {0};
    char myChar = 0;
    do
    {
        // Get the input
        myChar = getchar();
        // Make uppercase
        myChar = toupper(myChar);
        // Check if it is a workable character and increment
       // if (myChar - 65 >= 0 && myChar - 65 < 26)
        //{
            nums[myChar-65]++;
        //}
        // Break out of the loop on newline
    } while (myChar != '\n');

    for (int i = 0; i < 26; i++)
    {
        // Print the count of each character
        printf("%d\n", nums[i]);
    }
    
    return 0;
}