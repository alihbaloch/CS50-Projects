#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    // open file
    
    FILE *file = fopen("card.raw", "r");

    fread(buffer, 1, 4, card.raw);











}