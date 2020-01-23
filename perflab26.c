/*
    Author: Mark Howard
    2020-Jan-22
    Performance Lab 26
*/

#include <stdio.h>

int main(void)
{
    char userInput = 0;
    char tempValue = 0;
    char *input_ptr = NULL;
    input_ptr = &userInput;
    userInput = getchar();
    tempValue = *input_ptr;
    printf("userInput = %c, address = %p\ntempValue = %c, address = %p\ninput_ptr = %p, address = %p", userInput, &userInput, tempValue, &tempValue, input_ptr, &input_ptr);
}
