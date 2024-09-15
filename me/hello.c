#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}

//Pseudocode.
//Main function
//Use the command line inputs, and ensure that the user does the same.
//Check if the key is valid or invalid
// If all the above is true, then get the ciphertext and plaintext
//Implement the substitution function for each character in the ciphertext
//Return as plaintext.

#define CHAR_RANGE 128 // Assuming ASCII character set

bool isUniqueSet(char *str) {
    bool charSet[CHAR_RANGE] = {0}; // Initialize all values to false

    for (int i = 0; str[i] != '\0'; i++) {
        int val = (int)str[i];
        if (charSet[val]) { // If true, character already exists, hence not unique
            return false;
        }
        charSet[val] = true; // Mark character as seen
    }
    return true;
}

