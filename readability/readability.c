#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    // get input from user
    string text = get_string("Text: ");

    int letter_count = count_letters(text);
    printf("%i\n", letter_count);

}

int count_letters(string text)
{
    int count = 0;
    int length = strlen(text);

    for(int i = 0; i < length; i++)
        if(isupper(text[i]) || islower(text[i]))
        {
            count++;
        }
    return count;

}

int count_words(string text)
{
    int word = 0
    int


}