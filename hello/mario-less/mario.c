#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user input for height
    int height;
    do
    {
        height = get_int("Enter pyramid height: ");
    }
    while (height < 1 || height > 8);

    for (int block = 0; block < height; block++)

         // create a variable to print required spaces
        {
        for (int space = height; space > block; space--) // problem lies here! Come back to it after lecture 2!

            //printf(".");

            //create a variable to print hashes

        for (int block_2 = block; block_2 >= 0; block_2--) //check this one too, perhaps try using increments then go up print spaces
            {
                printf("#");
            }
                printf("\n");
        }

}

