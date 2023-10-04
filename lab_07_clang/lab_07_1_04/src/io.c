#include "libs.h"
#include "constants.h"

int get_len(char *filename, size_t *len)
{
    int err;
    int cur;

    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return INVALID_FILE;

    while ((err = fscanf(file, "%d", &cur)) == 1)
        *len += 1;

    if (!feof(file) || *len == 0)
    {
        fclose(file);
        return INVALID_DATA;
    }

    fclose(file);
    return OK;
}

int get_arr(char *filename, int *beg, int *end)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return INVALID_FILE;

    for (int *cur = beg; cur < end; cur++)
    {
        fscanf(file, "%d", cur);
    }

    fclose(file);
    return OK;
}

int print_in_file(char *filename, int *beg, int *end)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
        return INVALID_FILE;
    
    for (int *cur = beg; cur < end - 1; cur++)
    {
        fprintf(file, "%d ", *cur);
    }
    
    fprintf(file, "%d\n", *(end - 1));
    fclose(file);
    return OK;
}