#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int MAX_WORD_LENGTH = 50;

int compute_score(char *word);
void printWinner(int score1, int score2);

int main(int argc, char *argv[])
{
    printf("Player 1: ");
    char playerOneWord[MAX_WORD_LENGTH];
    scanf("%s", playerOneWord);

    printf("Player 2:");
    char playerTwoWord[MAX_WORD_LENGTH];
    scanf("%s", playerTwoWord);

    printWinner(compute_score(playerOneWord), compute_score(playerTwoWord));

    return 0;
}

int compute_score(char *word)
{
    int score = 0;

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isalpha(word[i]))
        {
            int index = tolower(word[i]) - 'a';
            score += POINTS[index];
        }
    }
    return score;
}

void printWinner(int score1, int score2)
{
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score2 > score1)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}
