// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
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

    for (int i = 0; DICTIONARY_H != NULL; i++)
    {
        if (strcasecmp(word)
        {
            return true;
        }

    }

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

    unint8_t buffer[word];

    node *n = malloc(sizof(node));

    if (n == NULL)
    {
        return false;
    }

    FILE *dictionary(fopen, "r");

    if (dictionary == NULL)
    {
        return false;
    }

    while (!(feof(dictionary)))
    {
         fscanf(dictionary, "%s", buffer)
         strcopy(n -> buffer)

    }




    while(fread(buffer, 1, LENGTH, dictionary) == LENGTH);
    {
        if (strcasecmp(buffer[]))
    }


    return false;
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
    return false;
}
