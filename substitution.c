#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

bool isnonalpha(string key);
bool isrepeated(string key);
void encipher(string plaintext, string key);

int main(int argc, string argv[])
{
    //get key
    //validate key
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (isnonalpha(argv[1]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    else if (isrepeated(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    //get plaintext
    string plaintext = get_string("plaintext:  ");
    //encipher
    //print ciphertext
    printf("ciphertext: ");
    encipher(plaintext, argv[1]);
    printf("\n");
    return 0;
}

bool isnonalpha(string key)//check if key contains nonalphabetic character
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isalpha(key[i]))
        {
            continue;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool isrepeated(string key)//check if character in key is repeated
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                return true;
            }
        }
    }
    return false;
}

void encipher(string plaintext, string key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int c = plaintext[i];
        if (islower(c))
        {
            printf("%c", tolower(key[c - 97]));
        }
        else if (isupper(c))
        {
            printf("%c", toupper(key[c - 65]));
        }
        else
        {
            printf("%c", c);
        }
    }
}
