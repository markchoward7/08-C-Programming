/*
    Author: Mark Howard
    2020-Jan-22
    Performance Lab 27
*/

#include <stdio.h>

// Define some errors even though only the abundant pointer is actually useful
#define ERROR_NULL_POINTER ((char*)-1)
#define ERROR_ABUNDANT_POINTER ((char*)-2)
#define ERROR_NULL_DELIMITER ((char*)-3)

// Function to split a string on a character
// Takes a string to split and a character delimiter to split it on
// Returns a pointer to the first character of the second string
// Returns an error if there are multiple instances of the delimiter
// Returns the original pointer if none found
char * split_the_string(char *string_ptr, char delimiter)
{
    // Check for null string or delimiter
    if (string_ptr == NULL)
    {
        return ERROR_NULL_POINTER;
    }
    if (delimiter == 0)
    {
        return ERROR_NULL_DELIMITER;
    }
    // Declare a return value pointer
    char *returnValue = NULL;
    // Loop through the string, ending on the first null character
    while (*string_ptr != 0)
    {
        // If character matches delimiter, check if there was already one found, if so error
        if (*string_ptr == delimiter)
        {
            if (returnValue != NULL)
            {
                return ERROR_ABUNDANT_POINTER;
            }
            else
            {
                returnValue = string_ptr;
            }
        }
        // Increment
        string_ptr++;
    }
    // Return string_ptr if no match
    if (returnValue == NULL)
    {
        return string_ptr;
    }
    // Return match otherwise
    return returnValue;
}

int main(void)
{
    // Initialize and get user input
    char string[256] = {0};
    char delimiter = 0;
    printf("Enter a string\n");
    scanf("%255[^\n]s", &string);
    fseek(stdin, 0, SEEK_END);
    printf("Enter a 1 character delimiter\n");
    delimiter = getchar();
    // Call the split_the_string function and set secondString to the return value
    char * secondString =  split_the_string(string, delimiter);
    // Check for error
    if (secondString == ERROR_ABUNDANT_POINTER || secondString == ERROR_NULL_DELIMITER || secondString == ERROR_ABUNDANT_POINTER)
    {
        printf("ERROR");
        return 1;
    }
    // Using the result, print the two substrings through the following loops...
    printf("First substring: ");
    // Loop through the original string until the end or finding the same address of the secondString pointer value
    for (int i = 0; i < 256 && string[i] != 0 && &string[i] != secondString; i++)
    {
        printf("%c", string[i]);
    }
    printf("\nSecond substring: ");
    // Loop through the second string until the end
    while (*secondString != 0)
    {
        printf("%c", *secondString);
        secondString++;
    }
    return 0;
}