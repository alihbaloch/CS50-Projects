#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_population;

    do

        start_population = get_int("What is population start size?: ");

    while (start_population < 9);
    // TODO: Prompt for end size

    int end_population;

    do

        end_population = get_int("What is population end size?: ");

    while (end_population < start_population);

    int years = 0;

    // TODO: Calculate number of years until we reach threshold
    {
        while (start_population < end_population)

        start_population = start_population + (start_population / 3) - (start_population / 4);
        years++;
    }
    // TODO: Print number of years

    printf("Years: %i\n", years);

}
