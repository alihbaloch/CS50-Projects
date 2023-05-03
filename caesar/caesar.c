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
    int int_key = atoi(argv[1]);

    if (!is_digits)
    {
        return 1;
    }

    //char c = 'Z' + 1;
    //printf("%c\n", c);

    string text = get_string("Plaintext: ");
    int text_length = strlen(text);

    int ci = (text[0] + int_key) % 26;
    printf("formula is %i\n", ci);

    //int t = strlen(text);

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


//char rotate(char c, int n)



    //char character;

    //if (character >= 'A' || character <= 'Z')
    //{
      //  character = c - character;
        //printf("%c\n", character);
    //}
    //if (character <= 'Z' || character <= 'z')
    //{
      //  character = c = character;
        //printf("%c\n", character);
    //}



    //int length = strlen(c)
    //char index = 'A';

    //for (int i = 0; i < 25; i++)
    //if(isupper([i])
   //{
      //  index = index + 1;
        //printf("%c\n", index);
   // }

    //return index;

