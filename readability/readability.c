#include <cs50.h>
#include <stdio.h>


int count_letters(string text);
int main(void)
{
    // get input from user
    string text = get_string("Text: ");
    printf("%s\n", text);

}

int count_letters(string text)
{
    int count = 0;
    int length = strlen(text);
    for(int i = 0;, i < length; i++)
        if(isupper(text[i]))
    {
        count += 
    }

    return count_letters;

}