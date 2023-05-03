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
    if (!is_digits)
    {
        return 1;
    }

    string text = get_string("Plaintext: ");
    int t = strlen(text);

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
    char alpha_index = 0;

    for (int i = 65; i <= 90; i++)
    //if(isupper[i])
    {
        alpha_index++;
        printf("%c\n", alpha_index);
    }

    return alpha_index;

}