#include "libs.h"

// Получить кол-во элементов в файле
int get_len_of_file(char *filename)
{
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
        return EXIT_FAILURE;

    int temp, count = 0;
    for (int i = 0; 1; i++)
    {
        fread(&temp, sizeof(temp), 1, file);
        if (feof(file))
        {
            fclose(file);
            return count;
        }
        count++;
    }
}

// Получить значение элемента по индексу
int get_number_by_pos(FILE *file, int index)
{
    int num;
    fseek(file, index * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, file);
    return num;
}

// Перезаписать элемент по индексу
void put_number_by_pos(FILE *file, int index, int num)
{
    fseek(file, index * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, file);
} 

// Функция пузырьковой сортировки для бинарного файла
void sort_file(char *filename)
{
    int length = get_len_of_file(filename);
    int num1, num2;

    FILE *file = fopen(filename, "r+b");

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            num1 = get_number_by_pos(file, j);
            num2 = get_number_by_pos(file, j + 1);

            if (num1 > num2)
            {
                put_number_by_pos(file, j, num2);
                put_number_by_pos(file, j + 1, num1);
            }
        }
    }

    fclose(file);
}