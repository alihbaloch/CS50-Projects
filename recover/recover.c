#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
int count = 0;
char image[8];
FILE *IMAGE;

int main(int argc, char *argv[])
{

    // Ensure 1 command line argument

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file using fopen in read mode

    FILE *JPEG = fopen(argv[1], "r");

    // If file cannot be opened print error message

    if (JPEG == NULL)
    {
        printf("Cannot be opened\n");
        return 1;
    }

    // Make an array/ buffer file to store data from file

    uint8_t buffer[BLOCK_SIZE];

    // Read file

    while (fread(buffer, 1, BLOCK_SIZE, JPEG) == BLOCK_SIZE)
    {
        // Check for signature

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If first jpeg

            if (count == 0)
            {
                sprintf(image, "%03i.jpg", count++);
                IMAGE = fopen(image, "w");
                fwrite(&buffer, 1, BLOCK_SIZE, IMAGE);
            }

            // If not the first jpeg / first close previous file

            else
            {
                fclose(IMAGE);
                sprintf(image, "%03i.jpg", count++);
                IMAGE = fopen(image, "w");
                fclose(image);
                fwrite(buffer, 1, BLOCK_SIZE, IMAGE);
            }
        }

        // Write subsequent blocks of data to the current file

        else if (count != 0)
        {
            fwrite(&buffer, 1, BLOCK_SIZE, IMAGE);
            fclose(IMAGE);
        }

        // Check for end of file and close remaining files

        if (feof(JPEG))
        {
            fclose(IMAGE);
            fclose(JPEG);
        }
    }

    return 0;

}