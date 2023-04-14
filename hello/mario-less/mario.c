#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Define all variables

    int block_v;
    int block_h;
    int space;
    int height;

    // Get user input for height

    do
    {
        height = get_int("Enter pyramid height: ");
    }
    while (height < 1 || height > 8);

    for (block_v = 0; block_v < height; block_v++)

        // Print required spaces
    {
        for (space = height - 1; space > block_v; space--)
            printf(" ");

        // Print hashes 

        for (block_h = block_v; block_h >= 0; block_h--)
        {
            printf("#");
        }
            printf("\n");
     }

}

