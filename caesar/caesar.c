#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    string key = argv[1];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // printf("Success!\n%s\n",key);
    string text = get_string("Enter a text:");
    int k = atoi(key);
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", (((text[i] - 65) + k) % 26) + 65);
        }
        else if (islower(text[i]))
        {
            printf("%c", (((text[i] - 97) + k) % 26) + 97);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}