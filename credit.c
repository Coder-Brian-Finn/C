#include <math.h>
#include <stdio.h>

// Correctly define constants with `=`
const int MULTIPLIER = 2;
const int BASE_10 = 10;
const int MASTERCARD_START_RANGE = 51;
const int MASTERCARD_END_RANGE = 55;
const int MASTERCARD_DIGITS = 16;
const int AMEX_START_RANGE = 34;
const int AMEX_END_RANGE = 37;
const int AMEX_DIGITS = 15;
const int VISA_START_DIGIT = 4;
const int VISA_MIN_DIGITS = 13;
const int VISA_MAX_DIGITS = 16;

int countDigits(unsigned long number);
int isValidLuhnChecksum(unsigned long number);
void printCardType(int firstDigit, int firstTwoDigits, int numberOfDigits);

int main(void)
{
    // Request credit card number from the user
    printf("Number: ");
    unsigned long ccNumber;
    // Validate input to check if a number was entered
    if (scanf("%lu", &ccNumber) != 1)
    {
        printf("INVALID INPUT\n");
        return 1;
    }

    int numberOfDigits = countDigits(ccNumber);
    // Get the first digit of the credit card
    int firstDigit = ccNumber / (long) pow(BASE_10, numberOfDigits - 1);
    // Get the first two digits of the credit card
    int firstTwoDigits = ccNumber / (long) pow(BASE_10, numberOfDigits - 2);

    // Check Luhn algorithm to validate the checksum
    if (isValidLuhnChecksum(ccNumber))
    {
        printCardType(firstDigit, firstTwoDigits, numberOfDigits);
    }
    else
        printf("INVALID\n");

    return 0;
}

// Function to count the number of digits in the credit card number
int countDigits(unsigned long number)
{
    int count = 0;
    while (number > 0)
    {
        number /= BASE_10;
        count++;
    }
    return count;
}

// Function to calculate the Luhn checksum
