#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare functions here
string lower_string(string s);
string cipher_create(string plain_text, string user_key);

// main
int main(int argc, string argv[])
{
    string key = argv[1];
    key = lower_string(key);
    if (argc == 2)
    {
        if (strlen(key) == 26)
        {
            string plain = get_string("plaintext:  ");
            printf("ciphertext:  ");
            cipher_create(plain, key);
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            exit(1);
            return (1);
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        exit(1);
        return (1);
    }
    exit(0);
    return (0);
}

// define functions here
string lower_string(string s)
{
    for (int i = 0; s[i]; i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

string cipher_create(string plain_text, string user_key)
{
    string cipher_text = 0;
    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        char c = plain_text[i];
        bool upper = isupper(c);
        if (isalpha(c) && upper)
        {
            int l = c - 65;
            char cipher = user_key[l];
            printf("%c", toupper(cipher));
        }
        else if (isalpha(c) && !upper)
        {
            int l = c - 97;
            char cipher = user_key[l];
            printf("%c", tolower(cipher));
        }
        else if (!isalpha(c))
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return (0);
}