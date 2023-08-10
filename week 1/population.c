#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int start;
    int end;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    double cur = (double) start;
    int years = 0;
    while (cur < (double) end)
    {
        cur = cur + (int) cur / 3 - (int) cur / 4;

        years++;
        // printf("%f at %d\n",cur,years);
    }

    printf("Years: %d\n", years);
}