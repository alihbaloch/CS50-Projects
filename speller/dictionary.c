// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#include "dictionary.h"

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

    //unint8_t buffer[];

    FILE *DICT = fopen(dictionary, "r");

    if (DICT == NULL)
    {
        return false;
    }

    //char buffer[Length + 1];

    while (fscanf(DICT, "%s", word) == EOF)  //(!(feof(DICT)))
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

         strcpy(word -> n)
         n -> next = NULL;
         hash(n);

    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    //if (word == NULL)
    //{
      //  return false;
    //}

    //while (word != NULL)
    //{
        //node *ptr = word -> next;
      //  free(n);
       // n = ptr;
    //}

    return true;
}
