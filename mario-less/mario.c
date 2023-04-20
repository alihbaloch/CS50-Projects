#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Define all variables

    int block_i;
    int block_j;
    int space;
    int height;

    // Get user input for height

    do
    {
        height = get_int("Enter pyramid height: ");
    }
    while (height < 1 || height > 8);

    for (block_i = 0; block_i < height; block_i++)

        // Print required spaces
    {
        for (space = height - 1; space > block_i; space--)
        {
            printf(" ");
        }

        // Print hashes

        for (block_j = block_i; block_j >= 0; block_j--)
        {
            printf("#");
        }
        printf("\n");
    }

}

