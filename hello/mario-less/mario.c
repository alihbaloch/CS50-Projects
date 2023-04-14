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
        for (space = height - 1; space > block; space--) // problem lies here! Come back to it after lecture 2!

            printf(".");

            //print hashes

        for (block_2 = block; block_2 >= 0; block_2--) //check this one too, perhaps try using increments then go up print spaces
            {
                printf("#");
            }
                printf("\n");
        }

}

