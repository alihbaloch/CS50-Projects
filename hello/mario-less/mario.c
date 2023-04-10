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
        for (int dot = 6; dot >= block; dot--) //Understand this tomorrow. Copy to google docs and make notes. Change folder to its own. Check errors using check50 then submit.
            printf(".");

        for (int block_2 = block; block_2 >= 0; block_2--)
            {
                printf("#");
            }
                printf("\n");
        }

}

