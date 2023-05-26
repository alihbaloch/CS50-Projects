#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Make an array/ buffer file to store data from file

    unint8_t buffer[4];

    // Open file

    FILE *file = fopen(argv[1], "r");

    fread(buffer, 1, 4, argv[1]);
    if (file == NULL)
    {
        printf("Cannot be opened\n");
        return 1
    }











}