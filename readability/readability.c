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
    printf("%i letters\n", letter_count); // not needed for reference

    int word_count = count_words(text);
    printf("%i words\n", word_count); //not needed FR

    int sentence_count = count_sentences(text);
    printf("%i sentences\n", sentence_count); // not needed FR

    float L = ((float) letter_count / word_count) * 100;
    printf("L is %f\n", L);

    float S = ((float) sentence_count / word_count) * 100;
    printf("S is %f\n", S);

    int grade_level = 0.0588 * L - 0.296 * S - 15.8;

    //if(grade_level < 1)            // NEED TO WORK ON LINE 30 - 40. FIGURE OUT HOW TO PRINT GRADE 2 - 15. FOR LOOP?
    {
    //    printf("Before Grade 1\n");
    }
   // else if(grade_level >= 16)
    {
    //    printf("Grade 16+\n");
    }
   // else
    {
        printf("Grade %i\n", grade_level);
    }

}


    //printf("Index value is %i\n", grade_level); // not needed FR

    //int calculate =  ((float) 65 / 14) * 100; // FR
    //printf("%i\n", calculate); this is done!

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