#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size = get_int("Enter the size of the block:");

    while (size < 1)
    {
        printf("Enter a positive number\n");
        size = get_int("What's the size?");
    }

    for (int i = 0; i < size; i++)
    {
        for (int x = 0; x < size; x++)
        {
            printf("#");
        }
        printf("\n");
    }

}

