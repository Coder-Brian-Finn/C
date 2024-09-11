#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int MAX_TEXT_LENGTH = 15000;
const int ASCII_FOR_SPACE = 32;

int main(int argc, char *argv[])
{
     char text[MAX_TEXT_LENGTH];
     printf("Text: ");
     scanf("%[^\n]s", text);
    int numberOfLetters = 0;
    int numberOfWords = 1;
    int numberOfSentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
            numberOfLetters++;
        else if (text[i] == ' ')
            numberOfWords++;
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            numberOfSentences++;
    }
    printf("Letters: %d\n", numberOfLetters);
    printf("Words: %d\n", numberOfWords);
    printf("Sentences: %d\n", numberOfSentences);

    float L = (float) numberOfLetters / (float) numberOfWords * 100;
    float S = (float) numberOfSentences / (float) numberOfWords * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
        printf("Before Grade 1\n");
    else if (index > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", index);

    return 0;
}
