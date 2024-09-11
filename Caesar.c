#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NUMBER_OF_ARGUMENTS = 2;
const int MAX_TEXT_LENGTH = 15000;

int main(int argc, char *argv[])
{
    if (argc != NUMBER_OF_ARGUMENTS)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);

    printf("Plaintext: ");
    char plainText[MAX_TEXT_LENGTH];
    scanf("%[^\n]s", plainText);
    printf("ciphertext: ");
    for (int i = 0, length = strlen(plainText); i < length; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                int c = plainText[i] - 'A';
                c = (c + key) % 26;
                printf("%c", 'A' + c);
            }
            else
            {
                int c = plainText[i] - 'a';
                c = (c + key) % 26;
                printf("%c", 'a' + c);
            }
        }
        else
            printf("%c", plainText[i]);
    }
    printf("\n");

    return 0;
}
