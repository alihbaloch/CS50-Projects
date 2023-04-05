#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int block;
    do
    {
        block = get_int("Enter Number: ");
    }
    while (block < 1 || block > 8);

    for (block = 0; block < 8; block++)
        for (int block_2 = 0; block_2 < 8; block_2++)

        printf("#");
        //printf("/n");
}