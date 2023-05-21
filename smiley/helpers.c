#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            if {rgbtred image [i][j] == 0.00 && rgbtblue image [i][j] == 0.00 && rgbtgreen image [i][j] == 0.00}
            {
                rgbtred image [i][j] == 0.FF;
            }
    }
}
