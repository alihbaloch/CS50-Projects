#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = get_string("Enter name: ");
    int length = strlen(name);

    //get length of string

    for (int i = 0, i < length, i++)
    {
        printf("%c", name[i]);
    }


}