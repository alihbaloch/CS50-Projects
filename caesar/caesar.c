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
    //int length = strlen(c)
    int A = 0;

    for (int i = 0; i < 25; i++)
    if(isupper(c(i))
    {
        A++;
        //printf("%c\n", alpha_index);
    }

    return A;

}