#include <stdio.h>

char stack[256];
int top = -1;

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if (top == 256)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char peek()
{
    return stack[top];
}

char pop()
{
    char data;

    if (!isempty())
    {
        data = stack[top];
        top--;
        return data;
    }
    else
    {
        printf("Stack is empty\n");
    }
}

void push(char data)
{
    if (!isfull())
    {
        top++;
        stack[top] = data;
    }
    else
    {
        printf("Stack is full\n");
    }
}

// int main(void)
// {
//     printf("Enter a string to reverse\n");
//     char c = getchar();
//     while (c != '\n')
//     {
//         push(c);
//         c = getchar();
//     }
//     printf("That string reversed is...\n");
//     while (!isempty())
//     {
//         printf("%c", pop());
//     }
//     return 0;
// }

#include <string.h>

int main(void)
{
    // Get input
    printf("Enter a string to check\n");
    char c = getchar();
    while (c != '\n')
    {
        // ensure only letters
        if ((c > 64 && c < 91) || (c > 96 && c < 123))
        {
            push(c);
        }
        c = getchar();
    }
    // copy stack
    char string[256];
    strcpy(string, stack);
    // loop to check copy to the popping of the stack
    int count = 0;
    while (!isempty())
    {
        if (string[count] != pop())
        {
            printf("Not a palindrome");
            return 0;
        }
        count++;
    }
    printf("Is a palindrome");
    return 0;
}