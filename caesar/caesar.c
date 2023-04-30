#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);
int main(int argc, string argv[])
{

 bool isdigits = only_digits(s);
    if (argv[s] == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

   return 0;

    if ((argc == 1) || (argc > 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        return 0;
    }


}

bool only_digits(string s)
{

    char digits[] = "0123456789";
    int length = strlen(s);

    for (int i = 0; i < length; i++)
        if ((digits[i]) && isdigit(s[i]))
        {
            printf("s is a digit %i\n", i);
            return true;
        }

    return false;

}
