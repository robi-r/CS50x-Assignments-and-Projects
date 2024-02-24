#include <cs50.h>
#include <math.h>
#include <stdio.h>
int evenDigit(long number);
int multiSum(int last);
int digitCount(long number);
bool isAmex(long number, int numDigit);
bool isMaster(long number, int numDigit);
bool isVisa(long number, int numDigit);

int main(void)
{
    long number = get_long("Enter credit card number:");
    int sum_evenDigit = evenDigit(number);
    int numDigit = digitCount(number);
    bool amex = isAmex(number, numDigit);
    bool master = isMaster(number, numDigit);
    bool visa = isVisa(number, numDigit);

    if (sum_evenDigit % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

bool isVisa(long number, int numDigit)
{
    if (numDigit == 13)
    {
        int first_digit = number / pow(10, 12);
        if (first_digit == 4)
        {
            return true;
        }
    }
    else if (numDigit == 16)
    {
        int first_digit = number / pow(10, 15);
        if (first_digit == 4)
        {
            return true;
        }
    }

    return false;
}

bool isMaster(long number, int numDigit)
{
    int first_two_digit = number / pow(10, 14);
    if ((numDigit == 16) && (first_two_digit > 50 && first_two_digit < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isAmex(long number, int numDigit)
{
    int first_two_digit = number / pow(10, 13);
    if ((numDigit == 15) && (first_two_digit == 34 || first_two_digit == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int digitCount(long number)
{
    int count = 0;
    while (number > 0)
    {
        count++;
        number = number / 10;
    }
    return count;
}

int evenDigit(long number)
{
    int sum = 0;
    bool altDigit = false;
    while (number > 0)
    {
        if (altDigit == true)
        {
            int last = number % 10;
            int product = multiSum(last);
            sum += product;
        }
        else
        {
            int last = number % 10;
            sum = sum + last;
        }
        altDigit = !altDigit;
        number = number / 10;
    }
    return sum;
}

int multiSum(int last)
{
    int multi = last * 2;
    int sum = 0;
    while (multi > 0)
    {
        int lastMulti = multi % 10;
        sum += lastMulti;
        multi = multi / 10;
    }
    return sum;
}