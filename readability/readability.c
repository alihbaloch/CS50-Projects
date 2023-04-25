#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    // get input from user
    string text = get_string("Text: ");

    // make variables to store functions
    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    //calculate letter and sentence averages and store them inside variables
    float L = ((float) letter_count / word_count) * 100;
    float S = ((float) sentence_count / word_count) * 100;

    //formula for calucating grade level
    float grade_level = 0.0588 * L - 0.296 * S - 15.8;

    //print grades
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(grade_level));
    }

}

int count_letters(string text)
{
    //count number of letters
    long int letters = 0;
    long int length = strlen(text);

    for (int i = 0; i < length; i++)
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
    return letters;

}

int count_words(string text)
{
    //count number of words
    long int words = 1;
    long int length = strlen(text);

    for (int i = 0; i < length; i++)
        if (text[i] == (' '))
        {
            words++;
        }
    return words;
}

int count_sentences(string text)
{
    //count number of sentences
    int sentences = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    return sentences;
}