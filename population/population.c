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
    while (end_population < 9);


    // TODO: Calculate number of years until we reach threshold
    

    // TODO: Print number of years

}
