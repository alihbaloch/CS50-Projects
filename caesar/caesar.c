#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);
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
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

bool only_digits(string s)
{

    //char digits[] = "0123456789";
    int length = strlen(s);

    for (int i = 0; i < length; i++)
        if (!isdigit(s[i]))
        {
            printf("s is NOT a digit %i\n", i);
            return false;
        }

    return true;

}
