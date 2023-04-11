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
        for (int dot = 6; dot >= block; dot--)

            printf(" ");
        printf("\n");



            //create a variable to print hashes

        for (int block_2 = block; block_2 >= 0; block_2--)
            {
                printf("#");
            }
                printf("\n");
        }

}

