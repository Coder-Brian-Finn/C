#include <ctype.h>   // For character classification functions like isalpha
#include <math.h>    // For mathematical functions like round
#include <stdio.h>   // For input/output functions
#include <string.h>  // For string manipulation functions like strlen

// Constants
const int MAX_TEXT_LENGTH = 15000;  // Maximum length for the input text

int main(int argc, char *argv[])
{
    // Declare a buffer to hold the input text
    char text[MAX_TEXT_LENGTH];
    
    // Prompt the user to enter the text
    printf("Text: ");
    
    // Read a line of input until a newline is encountered
    scanf("%[^\n]s", text);

    // Initialize counters for letters, words, and sentences
    int numberOfLetters = 0;
    int numberOfWords = 1; // Starts at 1 because the first word won't have a preceding space
    int numberOfSentences = 0;

    // Loop through each character in the input text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if the character is a letter
        if (isalpha(text[i]))
            numberOfLetters++;
        // Check if the character is a space (indicating the end of a word)
        else if (text[i] == ' ')
            numberOfWords++;
        // Check if the character is a sentence-ending punctuation
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            numberOfSentences++;
    }

    
    // Calculate average letters and sentences per 100 words
    float L = (float) numberOfLetters / (float) numberOfWords * 100;
    float S = (float) numberOfSentences / (float) numberOfWords * 100;

    // Use the Coleman-Liau formula to compute the readability index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Output the grade level based on the index
    if (index < 1)
        printf("Before Grade 1\n");
    else if (index > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", index);

    return 0;
}

