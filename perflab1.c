/*
    Author: Mark Howard
    2020-Jan-06
    Performance Lab 1
    This is a lab that shows that I know how to declare and initialize variables.
*/

// Include the standard input-output header file
#include <stdio.h>

// Main function where all the magic happens
int main(void)
{
    // Declare and initialize all them variables
	int myInteger = 1;
	float myFloat = 1.5;
	double myDouble = 1.5;
	char myCharacter = 'a';

	// Print out the data the variables hold as well as their size
	printf("Your integer is %d, its size is %ld \n", myInteger, sizeof(myInteger));
	printf("Your float is %f, its size is %ld \n", myFloat, sizeof(myFloat));
	printf("Your double is %lf, its size is %ld \n", myDouble, sizeof(myDouble));
	printf("Your character is %c, its size is %ld \n", myCharacter, sizeof(myCharacter));

	
	return 0;
}