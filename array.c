#include <stdio.h>
#include <cs50.h>

int main (void)

{
    int i;
    int size;
    do
    {
        size = get_int("Enter size: ");
    }
        while (size < 1);

    int array[size];
    array [0] = 1;
    printf("%i\n", array[0]);

    for (i = 1; i < size; i++)
    {
        //array[i] = 2 * array [i - 1];
        printf("%i\n", array[i]);
    }


}