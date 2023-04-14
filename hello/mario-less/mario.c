#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Define all variables

    int block;
    int block_2;
    int space;
    int height;

    // Get user input for height

    do
    {
        height = get_int("Enter pyramid height: ");
    }
    while (height < 1 || height > 8);

    for (block = 0; block < height; block++)

         // create a variable to print required spaces
        {
        for (space = height - 1; space > block; space--)
            printf(" ");

        //print hashes

        for (block_2 = block; block_2 >= 0; block_2--)
            {
                printf("#");
            }
                printf("\n");
        }

}

