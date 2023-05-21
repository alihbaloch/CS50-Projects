#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = average;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaGreen;
    int sepiaBlue;
    int sepiaRed;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //if (image[i][j].rgbtGreen > 255 || image[i][j].rgbtBlue > 255 || image[i][j].rgbtRed > 255)
            {
                //image[i][j].rgbtGreen = 255 && image[i][j].rgbtBlue = 255 && image[i][j].rgbtRed = 255;

                sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
                sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
                sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));

                if (sepiaGreen > 255)
                {
                    sepiaGreen = 255;
                }
                else if (sepiaBlue > 255)
                {
                    sepiaBlue = 255;
                }
                else if (sepiaRed > 255)
                {
                    sepiaRed = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = sepiaGreen;
                    image[i][j].rgbtBlue = sepiaBlue;
                    image[i][j].rgbtRed = sepiaRed;
                }

            }
        }

    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
