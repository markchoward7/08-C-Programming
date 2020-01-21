/*
    Author: Mark Howard
    2020-Jan-21
    Performance Lab 24
*/

#include <stdio.h>

#define COMBINE2(x, y) x##y
#define COMBINE(x, y) COMBINE2(x, y)
#define WRAP2(x) #x
#define WRAP(x) WRAP2(x)

#define BUFSIZE 64

int main(void)
{
    char myString[BUFSIZE] = {WRAP(COMBINE(First, Second))};
    printf("%s", myString);
    return 0;
}