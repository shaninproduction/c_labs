#include "libs.h"
#include "constants.h"


int process(FILE *f, int *max, int *last_max)
{
    *max = *last_max = INT_MIN;

    int num = 0, err, temp;
    
    if (fscanf(stdin, "%d %d", max, last_max) != 2)
        return NO_INPUT;

    if (*last_max > *max)
    {
        temp = *max;
        *max = *last_max;
        *last_max = temp;
    }

    while (1)
    {
        err = fscanf(f, "%d", &num);

        if (err != 1)
            return INVALID_INPUT;
        
        if (num > *max)
        {
            *last_max = *max;
            *max = num; 
        }
        else if (num > *last_max)
        {
            *last_max = num;
        }
    }
}

int main(void)
{
    int err, max, last_max;
    int *max_p = &max, *last_p = &last_max;
 
    err = process(stdin, max_p, last_p);

    if (err == NO_INPUT)
        return EXIT_FAILURE;

    printf("%d %d\n", max, last_max);

    return EXIT_SUCCESS;   
}