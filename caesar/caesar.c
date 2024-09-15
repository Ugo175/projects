#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string text);
char rotate(char c, int key);

// Main function that collects inputs from the command line terminal
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Key must be a positive integer.\n");
        return 1;
    }

    // Convert argv[1] to an integer
    int key = atoi(argv[1]);

    // Prompt the user for the text
    string plaintext = get_string("Plaintext:  ");

    // Implement rotation
    int text_length = strlen(plaintext);
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            plaintext[i] = rotate(plaintext[i], key);
        }
    }
    printf("Ciphertext: %s\n", plaintext);
    return 0;
}

// Check if the input is an integer
bool only_digits(string text)
{
    int length_of_string = strlen(text);
    for (int i = 0; i < length_of_string; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

// Encipher the plaintext
char rotate(char c, int key)
{
    if (isupper(c))
    {
        return 'A' + (c - 'A' + key) % 26;
    }
    else if (islower(c))
    {
        return 'a' + (c - 'a' + key) % 26;
    }
    return c; // Shouldn't reach here if input is always alphabetic
}
