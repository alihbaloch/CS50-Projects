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

    char digits[] = "0,1,2,3,4,5,6,7,8,9";
    int length = strlen(digits);

    for (int i = 0; i < length; i++)
        if (isdigit(digits[i]))
        {
            printf("s is a digit %i\n", length);
            return 1;
        }



            //digits++;

            //printf("%i\n", digits);
            //return digits;

}