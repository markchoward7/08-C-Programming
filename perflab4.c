/*
    Author: Mark Howard
    2020-Jan-07
    Performance Lab 4
*/

#include <stdio.h>

void main()
{
    // Declare and zeroize array
    char myString[256] = {0};

    // Set the individual elements of the array
    myString[0] = 'A';
    myString[1] = ' ';
    myString[2] = 'm';
    myString[3] = 'a';
    myString[4] = 'n';
    myString[5] = ' ';
    myString[6] = 'c';
    myString[7] = 'h';
    myString[8] = 'o';
    myString[9] = 'o';
    myString[10] = 's';
    myString[11] = 'e';
    myString[12] = 's';
    myString[13] = ',';
    myString[14] = ' ';
    myString[15] = 'a';
    myString[16] = ' ';
    myString[17] = 's';
    myString[18] = 'l';
    myString[19] = 'a';
    myString[20] = 'v';
    myString[21] = 'e';
    myString[22] = ' ';
    myString[23] = 'o';
    myString[24] = 'b';
    myString[25] = 'e';
    myString[26] = 'y';
    myString[27] = 's';
    myString[28] = '.';

    // This line is stupid.
    myString[255]= 0;

    // Print the stuff.
    printf("%s\n", myString);
    printf("Last character: __%c__\n", myString[-1]);
}