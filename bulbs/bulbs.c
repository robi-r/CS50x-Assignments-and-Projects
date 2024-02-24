#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Enter your message: ");
    for (int i = 0; i < strlen(message); i++)
    {
        unsigned char byte = message[i];
        int quotient = byte;
        int bit[BITS_IN_BYTE];
        int remainder;
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            remainder = quotient % 2;
            bit[j] = remainder;
            quotient /= 2;
        }
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(bit[k]);
        }
        printf("\n");
    }
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
