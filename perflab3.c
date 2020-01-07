/*
    Author: Mark Howard
    2020-Jan-07
    Performance Lab 3
*/

#include <stdio.h>

void main()
{
    // First part, fill an array with numbersr and print them out
    int studentAges[13] = {0};
    studentAges[0] = 69;
    printf("%d\n", studentAges[0]);
    for (int i = 1; i < sizeof(studentAges)/sizeof(studentAges[0]); i++)
    {
        studentAges[i] = 21 + i;
        printf("%d\n", studentAges[i]);
    }
    // Second part, fill an array with the characters of a quote, placing new lines after each word.
    char saying[] = "A man chooses, a slave obeys.";
    char sayingAdjusted[100] = {0};
    sayingAdjusted[99] = '\0';
    for (int i = 0; i < sizeof(saying)/sizeof(saying[0]); i++)
    {
        if (saying[i] != ' ')
        {
            sayingAdjusted[i] = saying[i];
        }
        else
        {
            sayingAdjusted[i] = '\n';
        }
        printf("%c", sayingAdjusted[i]);
    }
}