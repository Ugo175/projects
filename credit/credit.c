#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_int(char *text);
char *checksum(char *number);
void main_func(char *number);

int main()
{
    string number = get_string("Enter your credit card number: ");
    main_func(number);
    return 0;
}

// To check the validity of the input
int is_valid_int(char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isdigit(text[i]))
        {
            return 0; // false
        }
    }
    return 1; // true
}

// To implement Luhn's algorithm
char *checksum(char *number)
{
    if (is_valid_int(number))

    {
        int length = strlen(number);
        int new_number[length];
        int odd_nums[length];
        int new_index = 0, odd_index = 0;

        // Extract every other digit from the second-to-last digit and store them in new_number array
        for (int i = length - 2; i >= 0; i -= 2)
        {
            int digit = number[i] - '0';
            new_number[new_index++] = digit;
        }

        // Double every digit in new_number array and store them in mul_number array
        int mul_number[new_index];
        for (int i = 0; i < new_index; i++)
        {
            mul_number[i] = new_number[i] * 2;
        }

        // Calculate the sum of digits in mul_number array
        int their_sum = 0;
        for (int i = 0; i < new_index; i++)
        {
            while (mul_number[i] != 0)
            {
                their_sum += mul_number[i] % 10;
                mul_number[i] /= 10;
            }
        }

        // Extract the remaining digits and store them in odd_nums array
        for (int i = length - 1; i >= 0; i -= 2)
        {
            int digit = number[i] - '0';
            odd_nums[odd_index++] = digit;
        }

        // Calculate the sum of digits in odd_nums array
        int odd_sums = 0;
        for (int i = 0; i < odd_index; i++)
        {
            odd_sums += odd_nums[i];
        }

        // Calculate total sum
        int total_sum = odd_sums + their_sum;

        // Check if the total sum is divisible by 10
        if (total_sum % 10 == 0)
        {
            return "VALID";
        }
        return "INVALID";
    }

    // Print Invalid if the input contains a non integer
    else
    {
        printf("Input must be an integer\n");
        return "INVALID";
    }
}

// Check if the card is VISA, MASTERCARD or AMERICAN EXPRESS
void main_func(char *number)
{
    char *result = checksum(number);

    if (strcmp(result, "VALID") == 0)
    {
        char *Mcard[] = {"51", "52", "53", "54", "55"};
        char *AMEX[] = {"34", "37"};
        int Visa_lengths[] = {13, 16};

        int len = strlen(number);
        char prefix[3];
        strncpy(prefix, number, 2);
        prefix[2] = '\0';

        if ((strcmp(prefix, AMEX[0]) == 0 || strcmp(prefix, AMEX[1]) == 0) && len == 15)
        {
            printf("AMEX\n");
        }

        else if ((strcmp(prefix, Mcard[0]) == 0 || strcmp(prefix, Mcard[1]) == 0 || strcmp(prefix, Mcard[2]) == 0 ||
                  strcmp(prefix, Mcard[3]) == 0 || strcmp(prefix, Mcard[4]) == 0) &&
                 len == 16)
        {
            printf("MASTERCARD\n");
        }

        else if (number[0] == '4' && (len == Visa_lengths[0] || len == Visa_lengths[1]))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
