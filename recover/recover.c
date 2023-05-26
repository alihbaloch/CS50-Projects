#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Ensure 1 command line argument

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file using fopen in read mode

    FILE *jpeg = fopen(argv[1], "r");

    // If file cannot be opened print error message

    if (jpeg == NULL)
    {
        printf("Cannot be opened\n");
        return 1;
    }

    // Make an array/ buffer file to store data from file

    uint8_t buffer[4];

    // Read file

    fread(buffer, 1, 4, jpeg);

    uint8_t signature[] = {0xff, 0xd8, 0xff};

    for (int i = 0; i < 3; i++)
    {
        if !(buffer[i] == signature[i])
        {
            printf("Values are different\n");
            return 0;
        }
       
    }











}