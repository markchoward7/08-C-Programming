/*
    Author: Mark Howard
    2020-Jan-06
    Day Calculator

    Converts a number of days into the equivalent number of years, weeks, and days
*/

#include <stdio.h>

void main()
{
    // Declare and initialize variables
    int days = 0, weeks = 0, years = 0;
    // Get the days input from the user
    printf("Enter a number of days\n");
    scanf("%d", &days);
    printf("%d day(s) equates to ", days);

    // While loops to get the number of years and weeks
    while (days >= 365)
    {
        years++;
        days -= 365;
    }
    while (days >= 7)
    {
        weeks++;
        days -= 7;
    }
    // Prints only the relevant information
    if (years > 0)
    {
        printf("%d year(s), ", years);
    }
    if (weeks > 0)
    {
        printf("%d week(s), ", weeks);
    }
    printf("%d day(s)", days);
}