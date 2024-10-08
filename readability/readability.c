#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the average number of letters and sentences per 100 words
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    // Compute the Coleman-Liau index
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded_index = round(index);

    // Print the grade level
    if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded_index);
    }
}

int count_letters(string text)
{
    int count_1 = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            count_1++;
        }
    }
    return count_1;
}

int count_words(string text)
{
    int count_2 = 1;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            count_2++;
        }
    }
    return count_2;
}

int count_sentences(string text)
{
    int count_3 = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_3++;
        }
    }
    return count_3;
}
