#include <cs50.h>
#include <stdio.h>

int main(void)
{
    for (int block = 1; block < 8; block--)
    block = get_int("Type a number between 1-8: ");

    printf("#");

}