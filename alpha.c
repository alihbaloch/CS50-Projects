#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)

{
    string word = get_string("Enter word: ");
    int length = strlen(word);

    for(int i = 0; i < length - 1; i++)
    {
        if (word[i] > word[i + 1])
        {
            printf("Not alphabetical\n");
            return 0;
        }
    }

    printf("alphabetical\n");


}