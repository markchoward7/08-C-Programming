/*
    AUTHOR: Mark Howard
    2020-Jan-21
    Performance Lab 25
*/

#include <stdio.h>
#include <stdlib.h>
// Redefine EOF for funsies
#undef EOF
#define EOF 66

#define release 1
// Macro to print the macro name and value
#define PRINT(x) printf(#x " is %d\n", x)
// Only run if _INC_STDIO defined and just the same with release since I don't understand what the actual requirement was there
#if defined(release) && defined(_INC_STDIO)
int main(void)
{
    // Run the macros!
    PRINT(FOPEN_MAX);
    PRINT(FILENAME_MAX);
    PRINT(EOF);
    return 0;
}
#endif