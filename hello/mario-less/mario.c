#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter pyramid height: ");
    }
    while (height < 1 || height > 8);

    for (int block = 0; block < height; block++)
        {
        for (int dot = 6; dot >= block; dot--)
            printf(".");

        for (int block_2 = block; block_2 >= 0; block_2--)
            {
                printf("#");
            }
                printf("\n");
        }

}

