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

    while (fread(buffer, 1, 4, jpeg) == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
            {
                printf("Values are not the same\n");
                return false;
            }
        }

        return true;

    }

    //for (int i = 0; i < 4; i++)
    //{
      //  if (!(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
        //{
          //  printf("Values are not the same\n");
            //return 1;
        //}

    //}











}