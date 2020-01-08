/*
    Author: Mark Howard
    2020-Jan-08
    Performance Lab 8
*/

#include <stdio.h>

void demoLab4()
{
    // Read a string into a char array
    // Specify a field-width to protect against buffer overflow
    // Ensure the field-width leaves room for the nul-terminator
    // Stop reading at the first capital letter or new line
    char myString[20] = {0};
    printf("Enter your string\n");
    scanf("%19[^A-Z\n]s", myString);
    printf(myString);
}

void demoLab5()
{
    // Read three ints, representing the date, from one line
    // Format the input so the integers are separated by a dash (-) as <mm>-<dd>-<yyyy>
    // Output the results as a date with leading zeros <mm>/<dd>/<yyyy>
    // Specify the field width of the output appropriately
    int day, month, year;
    printf("Enter your date\n");
    scanf("%d%*c%d%*c%d", &month, &day, &year);
    printf("%02d/%02d/%04d", month, day, year);
}

void perfLab()
{
    // Read a first, middle and last name as input into separate char arrays
    // Specify a field-width to protect against buffer overflow
    // Ensure the field-width leaves room for a nul-terminator
    // Specify a ("\t") as a delimitating character
    // Print the full name, separating each string with a tab and newline ("\t\n")
    char firstName[20] = {0};
    char middleName[20] = {0};
    char lastName[20] = {0};

    printf("Enter your full name in the following format: First<tab>Middle<tab>Last\n");
    scanf("%19s%*c%19s%*c%19s", &firstName, &middleName, &lastName);
    printf("%s\t\n%s\t\n%s\t\n", firstName, middleName, lastName);

    // Read two integers from one line
    // Format the input so that the integers are separated by an asterisk (*) x*y (e.g., 2*3, 11*14)
    // Reprint the two integers and result as if the answer were being read by a human
    int num1, num2;

    printf("Enter two numbers separated by *\n");
    scanf("%d%*c%d", &num1, &num2);
    printf("The result of %d multiplied by %d is %d.", num1, num2, num1*num2);
}

void main()
{
    // Call the functions
    printf("Demo Lab 4\n");
    demoLab4();
    // Due to the first function potentially leaving extra stuff in stdin, call fseek
    // Fseek sets the pointer of the file (stdin) to a specified point
    // In this case, the end of the file, offset by 0
    // This way, future scanf calls will get new data instead of what was left earlier
    fseek(stdin,0,SEEK_END);
    // Continue calling the functions
    printf("\nDemo Lab 5\n");
    demoLab5();
    printf("\nPerformance Lab 8\n");
    perfLab();
}