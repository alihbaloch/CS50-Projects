// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#include "dictionary.h"

bool dict_loaded = FALSE;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    //for (int i = 0; DICTIONARY_H != NULL; i++)
    //{
      //  if (strcasecmp(word)
       // {
        //    return true;
        //}



    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *DICT = fopen(dictionary, "r");

    if (DICT == NULL)
    {
        return false;
    }
    else
    {
        dict_loaded == TRUE;
    }

    char buffer[LENGTH + 1];
    unsigned int word_counter = 0;
    unsigned int hash_index;

    while (fscanf(DICT, "%s", buffer) != EOF)  //(!(feof(DICT)))
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

         strcpy(n -> word, buffer);
         n -> next = NULL;

         hash_index = hash(buffer);
         printf("%s hashes to %i\n", buffer, hash_index);

         n -> next = table[hash_index];
         table[hash_index] = n;
         word_counter++;

    }

    fclose(DICT);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    unsigned int dict_words;

    if (dict_loaded == FALSE)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            node *ptr = table[i];
            ptr = ptr -> next;
            dict_words++;
        }
    }
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];

        while (ptr != NULL)
        {
            node *temp = ptr;
            ptr = ptr -> next;
            free(temp);

            if (temp == NULL)
            {
                return false;
            }
        }
    }

    return true;
}
