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

    //call only_digits function
    bool is_digits = only_digits(argv[1]);

    // convert key to int
    int int_key = atoi(argv[1]);

    if (!is_digits)
    {
        return 1;
    }

    //get plaintext from user
    string text = get_string("Plaintext:  ");
    int text_length = strlen(text);

    //convert to ciphertexts
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
    //get length of string s
    int length = strlen(s);

    //check for if NOT digits using negation
    for (int i = 0; i < length; i++)
        if (!isdigit(s[i]))
        {
            //print error message
            printf("Usage: ./caesar key\n");
            return false;
        }
    //return if digits
    return true;
}


char rotate(char c, int n)

{
    char ci;

    //check if alphabets
    //if (isalpha(c))
        if (isupper(c)) // if uppercase
        {
            ci = ((c - 'A' + n) % 26 + 'A');
        }

        else // if lowercase
        {
            ci = ((c - 'a' + n) % 26 + 'a');
        }
    //else // if not alphabets return as is
    //{
      //  ci = c;
    //}

    return ci;
}

