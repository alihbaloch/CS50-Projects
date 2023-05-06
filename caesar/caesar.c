#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);
int main(int argc, string argv[])

{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    bool is_digits = only_digits(argv[1]);

    // convert key to int
    int int_key = atoi(argv[1]);

    if (!is_digits)
    {
        return 1;
    }

    //get plaintext from user
    string text = get_string("Plaintext: ");
    int text_length = strlen(text);

    //convert to ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < text_length; i++)
    {
        //convert each letter to ciphertext
        char plaintext = text[i];
        //call rotate function inside loop using a variable
        char rotated = rotate(plaintext, int_key);
        //implement rotate function inside loop on each iteration
        printf("%c", rotated);
    }

    printf("\n");

    return 0;
}

bool only_digits(string s)
{
    int length = strlen(s);

    for (int i = 0; i < length; i++)
        if (!isdigit(s[i]))
        {
            printf("Usage: ./caesar key\n");
            return false;
        }

    return true;
}


char rotate(char c, int n)

{
    char ci;

    if (isalpha(c))
        if (isupper(c))
        {
            ci = ((c - 'A' + n) % 26 + 'A');
        }

        else
        {
            ci = ((c - 'a' + n) % 26 + 'a');
        }
    else
    {
        ci = c;
    }

    return ci;
}

