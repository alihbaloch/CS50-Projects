#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i;
    do
    {
        i = get_int("Enter pyramid height: ");
    }
    while (i < 1 || i > 8);

    for (i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            {
                printf("#");
            }
            printf("##\n");

        }

}
