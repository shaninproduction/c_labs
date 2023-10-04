#include "libs.h"
#include "constants.h"
#include "c_flag.h"
#include "p_flag.h"
#include "s_flag.h"

/**
 * Выбранный целочисленный тип - int
 * Алгоритм сортировки - сортировка пузырьком
 * Упорядочевание - от меньшего к большему
*/

int not_valid_file(char *filename)
{
    int len;
    
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
        return EXIT_FAILURE;
    
    fseek(file, 0, SEEK_END);
    len = ftell(file);

    if (len % 4 != 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int not_exist(char *filename)
{
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        return EXIT_FAILURE;
    }

    fclose(file);
    return EXIT_SUCCESS;
}


int main(int argc, char **argv)
{
    int err;

    // Проверка на кол-во входных параметров
    if (argc > 4 || argc < 3)
        return EXIT_FAILURE;

    // Ветка инициализации
    if (!strcmp(argv[1], "c"))
    {
        err = init_file(argv[2], argv[3]);

        if (err)
            return EXIT_FAILURE;
    }
    // Ветка вывода содержимого файла
    else if (!strcmp(argv[1], "p") && !not_exist(argv[2]) && !not_valid_file(argv[2]))
        show_file(argv[2]);

    // Ветка сортировки
    else if (!strcmp(argv[1], "s") && !not_exist(argv[2]) && !not_valid_file(argv[2]))
        sort_file(argv[2]);
    
    // Ошибочный ввод
    else
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}