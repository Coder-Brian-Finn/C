#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTES = 8;
const int MAX_MESSAGE_LENGTH = 5000;

void print_bulb(int bit);

int main(int argc, char *argv[])
{
    char message[MAX_MESSAGE_LENGTH];
    printf("Message: ");
    scanf("%[^\n]s", message);
    int n = strlen(message);
    ///int bits[BITS_IN_BYTES];

    for (int i = 0; i < n; i++)
    {
        int charNum = message[i];
        int bits[] = {0,0,0,0,0,0,0,0};
        int j = 0;
        while (charNum > 0)
        {
            bits[j] = charNum % 2;
            charNum /= 2;
            j++;
        }
        for (int k = BITS_IN_BYTES - 1; k >= 0; k--)
        {
            print_bulb(bits[k]);
        }
        printf("\n");
    }

    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
