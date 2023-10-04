#include "libs.h"
#include "constants.h"

// Заполняет файл псевдорандомными числами
int input_rand_numbers(FILE *file, char *number)
{
    int count = atoi(number);
    int num;

    if (count <= 0 || (int) (log10(count) + 1) != (int) strlen(number))
        return EXIT_FAILURE;

    for (int i = 0; i < count; i++)
    {
        num = rand() % 100;
        fwrite(&num, sizeof(int), 1, file);
    }

    return EXIT_SUCCESS;
}

// Инициализирует файл
int init_file(char *number, char *filename)
{   
    FILE *file = fopen(filename, "wb");
    int err;

    if (file == NULL)
        return EXIT_FAILURE;

    err = input_rand_numbers(file, number);

    if (err)
        return EXIT_FAILURE;

    fclose(file);

    return EXIT_SUCCESS;    
}