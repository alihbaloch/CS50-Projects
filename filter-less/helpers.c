#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // take average of RGB values

            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // convert to greyscale/ set all equal to average so they are same

            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = average;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           // calculate RGB values using original values and round them

           int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
           int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
           int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));

            // set cap to 255

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            // convert to sepia

            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // width / 2 to avoid overlap at midpoint

        for (int j = 0; j < (width / 2); j++)
        {
            // swap pixels from left to right using RGBTRIPLE temp variable

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int all_red;
    int all_blue;
    int all_green;
    float count;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            all_red = 0;
            all_blue = 0;
            all_green = 0;
            count = 0.0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k > height - 1 || j + l < 0 || j + l > width - 1)
                    {
                        continue;
                    }

                    all_red += image[i+k][j+l].rgbtRed;
                    all_blue += image[i+k][j+l].rgbtBlue;
                    all_green += image[i+k][j+l].rgbtGreen;

                    count++;
                }
            }

            copy[i][j].rgbtRed = round(all_red / count);
            copy[i][j].rgbtBlue = round(all_blue / count);
            copy[i][j].rgbtGreen = round(all_green / count);

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
        }
    }

    return;
}
