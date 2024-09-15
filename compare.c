#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = 0;
    int number = get_int("What's the number? ");

    if (x < number)
    {
        printf("x is less than number\n");
    }
    else if (x > number)
    {
        printf("x is greater than number\n");
    }

    return 0;
}
