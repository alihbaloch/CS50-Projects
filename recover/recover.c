#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open file

    FILE *buffer;

    FILE *file = fopen(argv[1], "r");

    fread(buffer, 1, 4, argv[1]);
    if (file == NULL)
    {
        printf("Cannot be opened\n");
        return 1
    }











}