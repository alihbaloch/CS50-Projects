// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#include "dictionary.h"

bool dict_loaded = false;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Optimize load factor to reduce collisions and determine size of buckets
const int words_dict = 143091;
const int words_text = 17756;
const float load_factor = 0.7;
const float Num_of_Elements = (words_dict + words_text) / load_factor;

// TODO: Choose number of buckets in hash table
const unsigned int N = Num_of_Elements;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    unsigned int hash_value = hash(word);
    node *ptr = table[hash_value];

    // check if word in dictionary

    while (ptr != 0)
    {
        if (strcasecmp(ptr -> word, word) == 0)
        {
            return true;
        }

        // move ptr to next value

        ptr = ptr -> next;
    }

    // if word not in dictionary return false

    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // Ref: https://www.youtube.com/watch?v=MXdF-n-hAQU

    unsigned int hash_value = 0;

    // iterate over each character
    for (int i = 0; i < strlen(word); i++)
    {
        // Multiply hash_value by 2 for even distribution
        hash_value = toupper(word[i]) + (hash_value * 2);
    }

    // Ensure valid index/ within table size and return
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // open dictionary file

    FILE *DICT = fopen(dictionary, "r");

    // return false if file is empty

    if (DICT == NULL)
    {
        return false;
    }
    // change bool variable to true

    if (DICT != NULL)
    {
        dict_loaded = true;
    }

    // variables to be used

    // buffer variable to read file from
    char buffer[LENGTH + 1];

    // to calculate hash value
    unsigned int hash_index;

    while (fscanf(DICT, "%s", buffer) != EOF)
    {
        // dynamically allocate space for node *n

        node *n = malloc(sizeof(node));

        // return false if no memory to allocate

        if (n == NULL)
        {
            return false;
        }

        // copy dictionary words to node n

        strcpy(n -> word, buffer);

        // hash word to obtain hash value

        hash_index = hash(buffer);

        // insert node into hash table

        n -> next = table[hash_index];
        table[hash_index] = n;

    }

    // close DICT file

    fclose(DICT);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    // variable to count number of words

    unsigned int dict_words = 0;

    // if dictionary not loaded return 0

    if (dict_loaded == false)
    {
        return 0;
    }
    // if dictionary loaded
    else
    {
        for (int i = 0; i < N; i++)
        {
            // initialize ptr to the number of buckets in table

            node *ptr = table[i];

            // until the end of table is reached

            while (ptr != NULL)
            {
                // keep moving ptr to next

                ptr = ptr -> next;

                // keep adding words

                dict_words++;
            }
        }
    }
    return dict_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        // initialize ptr to the number of buckets

        node *ptr = table[i];

        // until the end of table is reached

        while (ptr != NULL)
        {
            // create a new temp node and initialize its value to ptr

            node *temp = ptr;

            // return false if temp has no value

            if (temp == NULL)
            {
                return false;
            }

            // keep moving ptr to next to cover all values

            ptr = ptr -> next;

            // free temp node

            free(temp);
        }
    }

    return true;
}
