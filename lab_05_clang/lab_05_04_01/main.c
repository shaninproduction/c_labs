#include "libs.h"
#include "constants.h"
#include "io.h"
#include "sort.h"
#include "delete.h"

int not_valid_file(char *filename)
{
    int len;
    
    FILE *file = fopen(filename, "rb");
    struct person temp;
    if (file == NULL)
        return EXIT_FAILURE;
    
    fseek(file, 0, SEEK_END);
    len = ftell(file);
    if (len % sizeof(temp) != 0)
        return EXIT_FAILURE;
    
    fclose(file);
    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    int length;

    if (argc != 3 || (strcmp(argv[1], "db") != 0 && strcmp(argv[1], "sb") != 0))
        return INVALID_FLAG;

    // Ветка сортировки
    if (strcmp(argv[1], "sb") == 0 && !not_valid_file(argv[2]))
    {
        length = get_len_of_file(argv[2]);

        if (length == 0)
            return EXIT_FAILURE;

        sort_file(argv[2], length);
        show_file(argv[2]);
    }
    // Ветка удаления элемента
    else if (strcmp(argv[1], "db") == 0 && !not_valid_file(argv[2]))
    {
        length = get_len_of_file(argv[2]);
        
        if (length == 0)
            return EXIT_FAILURE;

        delete_person(argv[2], length);
    }
    
    return EXIT_SUCCESS;
}