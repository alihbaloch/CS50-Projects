#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // loop to check for height
    for (int i = 0; i < height; i++)
    {
        // nested for loop to check for width
        for (int j = 0; j < width; j++)
        {
            // first check if color is black
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00)
            {
                //if yes then excecute below

                //change color to yellow
                image[i][j].rgbtRed = 0xFF;
                image[i][j].rgbtGreen = 0xDD;
            }
        }
    }
}
