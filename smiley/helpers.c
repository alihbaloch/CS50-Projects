#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            if (image[i][j].rgbtred == 0x00 && image[i][j].rgbtblue == 0x00 && image[i][j].rgbtgreen == 0x00)
            {
                image[i][j].rgbtred = 0xFF;
            }
    }
}
