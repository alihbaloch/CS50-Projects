#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int block;
    const int n = 10;
    do
    {
        block = get_int("Enter pyramid height: ");
    }
    while (block < 1 || block > 8);

    for (block = 0; block < n; block++)
        {
            for (int block_2 = 0; block_2 < n; block_2++)
                {
                 printf("%i ", block_2);
                }
                printf("\n");
        }

}

