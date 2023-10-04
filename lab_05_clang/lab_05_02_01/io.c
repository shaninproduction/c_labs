#include "libs.h"
#include "constants.h"

int check_file(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    double num;
    int is_empty = 0;
    char smb;

    if (file == NULL)
        return EXIT_FAILURE;

    while (fscanf(file, "%lf%c", &num, &smb) == 2)
    {
        is_empty++;
        if (smb != ' ' && smb != '\n')
            return EXIT_FAILURE;
    }

    if (!feof(file) || is_empty < 2)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

double find_average(char *file_name)
{
    FILE *file = fopen(file_name, "r");

    float max = INT_MIN, min = INT_MAX;
    float num; 

    while (fscanf(file, "%f", &num) == 1)
    {
        if (num > max)
            max = num;
        
        if (num < min)
            min = num;
    }

    fclose(file);

    return (max + min) / 2;
}

int find_count(char *file_name, double average)
{
    FILE *file = fopen(file_name, "r");
    int count = 0;
    double num;

    while (fscanf(file, "%lf", &num) == 1)
    {   
        if (num > average)
            count++;
    }

    return count;
}
