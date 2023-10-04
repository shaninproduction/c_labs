#include "libs.h"
#include "constants.h"
#include "io.h"

int main(int argc, char **argv)
{
    int err;

    if (argc != 2)
        return EXIT_FAILURE;

    char *file_name = argv[1];

    err = check_file(file_name);

    if (err)
        return EXIT_FAILURE;

    float average = find_average(file_name);      

    int count = find_count(file_name, average);

    printf("Count of numbers > average : %d\n", count);

    return EXIT_SUCCESS;
}