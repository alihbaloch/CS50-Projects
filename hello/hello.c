#include <cs50.h>
#include <stdio.h>
int main(void)

{
    // get input/ask question

    string name = get_string("What is your name?: ");

    // use placeholder for the answer

    printf("Hello, %s!\n", name);

}