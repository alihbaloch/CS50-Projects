#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //int average = round((image[height][width].rgbtRed + image[height][width].rgbtGreen + image[height][width].rgbtBlue) / 3.0);
    float average;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[height][width].rgbtRed + image[height][width].rgbtGreen + image[height][width].rgbtBlue) / 3.000);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = average;

            //image[i][j].rgbtRed = (average);
            //image[i][j].rgbtBlue = (average);
            //image[i][j].rgbtGreen = (average);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
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
