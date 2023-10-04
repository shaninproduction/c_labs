#include "libs.h"
#include "constants.h"

// Получить кол-во элементов в файле
int get_len_of_file(char *filename)
{
    FILE *file = fopen(filename, "rb");
    struct person temp;

    if (file == NULL)
        return EXIT_FAILURE;

    fseek(file, 0, SEEK_END);
    int length = (int) ftell(file) / sizeof(temp);
    fclose(file);
    return length;
}

// Получить значение элемента по индексу
struct person get_struct_by_pos(FILE *file, int index)
{
    struct person temp;
    fseek(file, index * sizeof(temp), SEEK_SET);
    fread(&temp, sizeof(temp), 1, file);
    return temp;
}

// Перезаписать элемент по индексу
void put_struct_by_pos(FILE *file, int index, struct person cur)
{
    fseek(file, index * sizeof(cur), SEEK_SET);
    fwrite(&cur, sizeof(cur), 1, file);
} 

// Функция пузырьковой сортировки для бинарного файла
void sort_file(char *filename, int length)
{
    struct person pers1, pers2;

    FILE *file = fopen(filename, "r+b");

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            pers1 = get_struct_by_pos(file, j);
            pers2 = get_struct_by_pos(file, j + 1);

            if (strcmp(pers1.lastname, pers2.lastname) > 0)
            {
                put_struct_by_pos(file, j, pers2);
                put_struct_by_pos(file, j + 1, pers1);
            }
            else if (strcmp(pers1.lastname, pers2.lastname) == 0)
            {
                if (strcmp(pers1.name, pers2.name) > 0)
                {
                    put_struct_by_pos(file, j, pers2);
                    put_struct_by_pos(file, j + 1, pers1);
                }
            }
        }
    }

    fclose(file);
}