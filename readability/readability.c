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
    printf("%i letters\n", letter_count);

    int word_count = count_words(text);
    printf("%i words\n", word_count);

    int sentence_count = count_sentences(text);
    printf("%i sentences\n", sentence_count);

    int L = ((float) letter_count / word_count) * 100;

    int S = ((float) sentence_count / word_count) * 100;

    int grade_level = 0.0588 * L - 0.296 * S - 15.8;

    printf("Index value is %i\n", grade_level);

    //int calculate =  ((float) 65 / 14) * 100;
    //printf("%i\n", calculate);

}

int count_letters(string text)
{
    long int letters = 0;
    long int length = strlen(text);

    for(int i = 0; i < length; i++)
        if(isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
    return letters;

}

int count_words(string text)
{
    long int words = 1;
    long int length = strlen(text);

    for(int i = 0; i < length; i++)
        if(text[i] == (' '))
        {
            words++;
        }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    int length = strlen(text);

    for(int i = 0; i < length; i++)
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    return sentences;
}