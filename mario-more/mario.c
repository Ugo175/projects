#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int Height = get_int("Enter a height between 1 and 8: ");

    if (1 <= Height && Height <= 8)
    {
        int m = Height;

        for (int i = 1; i <= Height; i++)
        {
            int n = m--;
            char space[20] = "";
            char hash[20] = "";

            for (int j = 1; j < n; j++)
            {
                strcat(space, " ");
            }

            for (int x = 0; x < i; x++)
            {
                strcat(hash, "#");
            }

            printf("%s%s  %s\n", space, hash, hash);
        }
        return 0;
    }
    else
    {
        printf("The height of the triangle must be between 1 and 8\n");
    }

    return 1;
}
