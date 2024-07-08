#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = (BYTE)avg;
            image[i][j].rgbtGreen = (BYTE)avg;
            image[i][j].rgbtBlue = (BYTE)avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float sepiaRed = round((image[i][j].rgbtRed * .393) + (image[i][j].rgbtGreen * .769) + (image[i][j].rgbtBlue * .189));
            float sepiaGreen = round((image[i][j].rgbtRed * .349) + (image[i][j].rgbtGreen * .686) + (image[i][j].rgbtBlue * .168));
            float sepiaBlue = round((image[i][j].rgbtRed * .272) + (image[i][j].rgbtGreen * .534) + (image[i][j].rgbtBlue * .131));

            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;

            image[i][j].rgbtRed = (BYTE)sepiaRed;
            image[i][j].rgbtGreen = (BYTE)sepiaGreen;
            image[i][j].rgbtBlue = (BYTE)sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            int tempRed = image[i][j].rgbtRed;
            int tempGreen = image[i][j].rgbtGreen;
            int tempBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width-1-j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue;

            image[i][width-1-j].rgbtRed = tempRed;
            image[i][width-1-j].rgbtGreen = tempGreen;
            image[i][width-1-j].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int counts = 0;
            int R = 0, G = 0, B = 0;

            for (int row = i-1; row <= i+1; row++) {
                for (int col = j-1; col <= j+1; col++) {
                    if (row >= 0 && col >= 0 && row < height && col < width) {
                        R += copy[row][col].rgbtRed;
                        G += copy[row][col].rgbtGreen;
                        B += copy[row][col].rgbtBlue;
                        counts++;
                    }
                }
            }

            float avgR = round(R/(float)counts);
            float avgG = round(G/(float)counts);
            float avgB = round(B/(float)counts);

            image[i][j].rgbtRed = (BYTE)avgR;
            image[i][j].rgbtGreen = (BYTE)avgG;
            image[i][j].rgbtBlue = (BYTE)avgB;
        }
    }
    return;
}
