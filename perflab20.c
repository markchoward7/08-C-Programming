/*
    Author: Mark Howard
    2020-Jan-14
    Performance Lab 20
*/

#include <stdio.h>

// Function to take a string, a character to replace, and a character to replace it with
// Will search through the string and replace all instances of the first character parameter with the second
// Will return a count of the number of characters replaced
int replace_character(char * myString, const char findThisChar, const char replaceItWithThis)
{
    int returnValue = 0, counter = 0;
    while (myString[counter] != 0)
    {
        if (myString[counter] == findThisChar)
        {
            myString[counter] = replaceItWithThis;
            returnValue++;
        }
        counter++;
    }
    return returnValue;
}

int main(void)
{
    // Get user input for string, character to find, and character to replace
    char myString[256] = {0};
    printf("Enter a string to alter:\n");
    scanf("%255[^\n]s", &myString);
    fseek(stdin, 0, SEEK_END);
    char findThisChar, replaceItWithThis;
    printf("Enter a character to replace:\n");
    scanf("%c", &findThisChar);
    fseek(stdin, 0, SEEK_END);
    printf("Enter a character to replace it with:\n");
    scanf("%c", &replaceItWithThis);
    // Call the function putting the return value into the replaced variable
    int replaced = replace_character(myString, findThisChar, replaceItWithThis);
    // Print the results
    printf("Result: %s\nReplaced %d character(s).", myString, replaced);
    return 0;
}