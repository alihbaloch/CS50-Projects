#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float dot = 3.0;
    int height;
    do
    {
        height = get_int("Enter pyramid height: ");
    }
    while (height < 1 || height > 8);

    for (int block = 0; block < height; block++, dot++)
        {
            for (int block_2 = block; block_2 >= 0; block_2--)
                {
                 printf("#");
                }
                printf("\n");
        }

}

