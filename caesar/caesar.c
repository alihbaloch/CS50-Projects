#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);
int main(int argc, string argv[])
{
    if ((argc == 1) || (argc > 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        return 0;
    }

    //int digits_only = only_digits(s);
    //if (argv[1])
}

bool only_digits(string s)
{
    int digits = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++)
        if ((isdigit(s[i] >= 0)) || (isdigit(s[i] < 10)))
        {
            digits++;

            printf("%i\n", digits);
            //return digits;
        }
}