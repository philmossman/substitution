#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare functions here
string lower_string(string s);
string cipher_create(string plain_text, string user_key);
bool unique_characters(string s);
bool string_isalpha(string s);

// main
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        key = lower_string(key);
        if (strlen(key) == 26 && unique_characters(key) && string_isalpha(key))
        {
            string plain = get_string("plaintext:  ");
            printf("ciphertext:  ");
            cipher_create(plain, key);
        }
        else
        {
            printf("Key must contain 26 individual alphabetical characters.\n");
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
// lower_string is a function to convert a string to all lower case
string lower_string(string s)
{
    for (int i = 0; s[i]; i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

// cipher_create is a function to create a ciphertext from a plain text and key input
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

// unique_characters is a function to check a string for unique characters
bool unique_characters(string s)
{
    for (int i = 0; i < (strlen(s) - 1); i++)
    {
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                return false;
            }
        }
    }
    return true;
}

// string_isaplpha is a function that checks whether a string contains only alphabetical characters
bool string_isalpha(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}