#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int block;
    int height = get_int("Enter pyramid height: ");
   // do
    //{
     //   block = get_int("Enter pyramid height: ");
    //}
    //while (block < 1 || block > 8);

    for (block = 0; block < height; block++)
        {
            for (int block_2 = 0; block_2 < height; block_2++)
                {
                 printf("%i ", block_2);
                }
                printf("\n");
        }

}

