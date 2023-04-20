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

    int word_count = count_words(text);
    printf("%i\n", word_count);

}

int count_letters(string text)
{
    int letters = 0;
    int length = strlen(text);

    for(int i = 0; i < length; i++)
        if(isupper(text[i]) || islower(text[i]))
        {
            count++;
        }
    return letters;

}

int count_words(string text)
{
    int words = 0;
    int length = strlen(text);

    for(int i = 0; i <= length; i++)
        {
            word++;
        }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    int length =
}