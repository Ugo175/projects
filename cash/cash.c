#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int validate(int c)
{
    if (c > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int cash()
{
    int change_owed;

    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (validate(change_owed) == false);

    int count_quarter = 0, count_dime = 0, count_nickel = 0, count_cent = 0;

    while (change_owed >= 25)
    {
        int new = change_owed - 25;
        change_owed = new;
        count_quarter++;
    }

    while (change_owed >= 10)
    {
        int new = change_owed - 10;
        change_owed = new;
        count_dime++;
    }

    while (change_owed >= 5)
    {
        int new = change_owed - 5;
        change_owed = new;
        count_nickel++;
    }

    while (change_owed >= 1)
    {
        int new = change_owed - 1;
        change_owed = new;
        count_cent++;
    }

    int total_count = count_quarter + count_dime + count_nickel + count_cent;
    printf("%d\n", total_count);
    return 0;
}

int main(void)
{
    cash();
    return 0;
}
