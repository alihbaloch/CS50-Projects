#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string name;
    int votes;

}
candidate;
candidate get_candidate(string prompt);

int main(void);
{
    candidate = get_candidate("Enter candidate: ");
    printf("%s\n", candidate.name);
    printf("%i\n", candidate.votes);

}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c;
    c.name = get_string("Enter name: ");
    c.votes = get_int("Enter votes: ");

    return c;

}
