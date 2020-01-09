
/*
    Author: Mark Howard
    2020-Jan-09
    Performance Lab 9
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Write a program to calculate the hypotenuse of a right triangle
    // Use the Pythagorean Theorem (a^2 + b^2 = c^2)
    // Input the two legs (A and B)
    // Output the hypotenuse (C)
    double a, b, c;
    printf("Enter the length of side 1\n");
    scanf("%lf", &a);
    printf("Enter the length of side 2\n");
    scanf("%lf", &b);
    // If either leg is 0 or less, then it isn't valid.
    if (a > 0 && b > 0)
    {
        // Calculate the hypotenuse.
        c = sqrt(a*a + b*b);
        printf("The hypotenuse is %lf", c);
    }
    else
    {
        printf("Side lengths must be greater than 0.");
    }
    
    return 0;
}