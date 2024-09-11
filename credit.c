#include <math.h>
#include <stdio.h>

const int MULTIPLIER 2;
const int BASE_10 10;
const int MASTERCARD_START_RANGE 51;
const int  MASTERCARD_END_RANGE 55;
const int MASTERCARD_DIGITS 16;
const int AMEX_START_RANGE 34;
const int AMEX_END_RANGE 37;
const int AMEX_DIGITS 15;
const int  VISA_START_DIGIT 4;
const int VISA_MIN_DIGITS 13;
const int VISA_MAX_DIGITS 16;

int countDigits(unsigned long number);
int isValidLuhnChecksum(unsigned long number);
void printCardType(int firstDigit, int firstTwoDigits, int numberOfDigits);

int main(void)
{
    // long exampleNumber = 4003600000000014;
    printf("Number: ");
    unsigned long ccNumber;
    // Validate input and check if a number was entered
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

    if (isValidLuhnChecksum(ccNumber))
    {
        printCardType(firstDigit, firstTwoDigits, numberOfDigits);
    }
    else
        printf("INVALID\n");

    return 0;
}

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
// Function to calculate the Luhn sum for both odd and even indexed digits
int isValidLuhnChecksum(unsigned long number)
{
    int sum = 0;
    // Multiply every second digit by 2, adjust if the product is more than 9
    for (int i = 0; number != 0; i++, number /= BASE_10)
    {
        if (i % 2 == 0)
            sum += number % BASE_10;
        else
        {
            int digit = (number % BASE_10) * MULTIPLIER;
            // Add the digits if greater than 9
            sum += digit < BASE_10 ? digit : (digit % BASE_10) + (digit / BASE_10);
        }
    }
    return (sum % BASE_10) == 0;
}

// Function that prints out what card otherwise prints "INVALID"
void printCardType(int firstDigit, int firstTwoDigits, int numberOfDigits)
{
    if ((firstTwoDigits >= MASTERCARD_START_RANGE && firstTwoDigits <= MASTERCARD_END_RANGE) &&
        numberOfDigits == MASTERCARD_DIGITS)
        printf("MASTERCARD\n");
    else if (firstDigit == VISA_START_DIGIT &&
             (numberOfDigits == VISA_MIN_DIGITS || numberOfDigits == VISA_MAX_DIGITS))
        printf("VISA\n");
    else if ((firstTwoDigits == AMEX_START_RANGE || firstTwoDigits == AMEX_END_RANGE) &&
             numberOfDigits == AMEX_DIGITS)
        printf("AMEX\n");
    else
        printf("INVALID\n");
}
