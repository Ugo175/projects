#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substitution(string key, string plaintext);
bool check_digit(string text);
bool isUniqueSet(char *str);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: /.substitution key\n");
        return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("Key must be 26 letters of the alphabet!\n");
        return 1;
    }

    else if (check_digit(argv[1]) && isUniqueSet(argv[1]))
    {
        string plaintext = get_string("Plaintext: ");
        int len_plaintext = strlen(plaintext);
        substitution(argv[1], plaintext);
        return 0;
    }
    return 1;
}

bool check_digit(string text)
{
    int len_text = strlen(text);
    for (int i = 0; i < len_text; i++)
    {
        if (isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

#define CHAR_RANGE 128 // Assuming ASCII character set

bool isUniqueSet(char *str)
{
    bool charSet[CHAR_RANGE] = {0}; // Initialize all values to false

    for (int i = 0; str[i] != '\0'; i++)
    {
        int val = (int) str[i];
        if (charSet[val])
        { // If true, character already exists, hence not unique
            return false;
        }
        charSet[val] = true; // Mark character as seen
    }
    return true;
}

int substitution(string key, string plaintext)
{
    int length = strlen(plaintext);
    char ciphertext[30];

    for (int i = 0; i < length; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[length] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
