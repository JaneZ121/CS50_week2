#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string key);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            printf("%c", rotate(plaintext[i], atoi(argv[1])));
        }
        printf("\n");
        return 0;
    }
}

bool only_digits(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (key[i] < '0' || key[i] > '9')
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{

    if (isupper(c))
    {
        return (c - 65 + key) % 26 + 65;
    }
    else if (islower(c))
    {
        return (c - 97 + key) % 26 + 97;
    }
    else
    {
        return c;
    }
}