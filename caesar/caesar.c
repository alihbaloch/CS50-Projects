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

    int length = strlen(s);
    int i;

    for (i = 0; i < length; i++)
        if (isdigit(s[i]))
        {
            printf("s is a digit %i\n", i);
            return 0;
        }



            //digits++;

            //printf("%i\n", digits);
            //return digits;

}